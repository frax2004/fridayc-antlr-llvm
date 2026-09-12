#include <fridayc.hpp>


namespace friday::inline api {

  auto LLVMObjectEmitterVisitor::visitFreeFunctionStatement(FridayParser::FreeFunctionStatementContext *ctx) -> any {
    // Get the function declaration
    Function* decl = $(ctx).function;

    // Get the llvm function declaration
    llvm::Function* func = llvm::dyn_cast<llvm::Function>(this->query(dynamic_cast<ISymbol*>(decl)));
    $(ctx).llvm_function = func;

    // Insert the alloca block
    llvm::BasicBlock* allocaBB = llvm::BasicBlock::Create(LLVM.context(), ".alloca-block", func);

    // Insert the entry point block
    llvm::BasicBlock* entryBB = llvm::BasicBlock::Create(LLVM.context(), ".entry-block", func);

    // Switch to the alloca block
    LLVM.builder().SetInsertPoint(allocaBB);

    // Connect alloca block to the entry point block
    LLVM.builder().CreateBr(entryBB);

    // Switch to the entry point block
    LLVM.builder().SetInsertPoint(entryBB);

    // Bind the parameters
    for(auto i : views::indices(decl->get_params_size())) {
      // Get the symbol
      Variable* var = decl->get_param_binding(i);

      // Get the value
      llvm::Argument* arg = func->getArg(i);

      // Allocate parameter on the stack
      llvm::AllocaInst* alloca = this->emit_alloca(arg->getType());

      // Store the value of the parameter
      LLVM.builder().CreateStore(arg, alloca);

      // Bind the value
      this->bind(
        dynamic_cast<ISymbol*>(var),
        llvm::cast<llvm::Value>(alloca)
      );
    }

    this->visitChildren(ctx);

    // Ensure a terminator is present
    if(LLVM.builder().GetInsertBlock()->getTerminator() == nullptr) {
      if(func->getReturnType() == LLVM.get_void_type())
        LLVM.builder().CreateRetVoid();
      else LLVM.builder().CreateUnreachable();
    }

    return {};
  }

  auto LLVMObjectEmitterVisitor::visitNativeFunctionStatement(FridayParser::NativeFunctionStatementContext *ctx) -> any {
    Function* decl = $(ctx).function;

    $(ctx).llvm_function = llvm::cast<llvm::Function>(this->query(dynamic_cast<ISymbol*>(decl)));
    return {};
  }

  auto LLVMObjectEmitterVisitor::visitStructStatement(FridayParser::StructStatementContext *ctx) -> any {
    $(ctx).llvm_struct = llvm::cast<llvm::StructType>($(ctx).struct_->to_llvm_type());
    this->visitChildren(ctx);
    return {};
  }

  auto LLVMObjectEmitterVisitor::visitPrintStatement(FridayParser::PrintStatementContext *ctx) -> any {
    this->visitChildren(ctx);

    string fmt = $(ctx).fmt;
    Value arg = $(ctx->expression()).value;

    Type* byteptrType = Type::get_byteptr_type();
    
    // Get the format string
    llvm::Value* formatter = this->emit_value(Value::from_constant(byteptrType, Constant::from_str(fmt)));

    // Get the value
    llvm::Value* value = this->emit_value(arg);

    // Call to C printf
    this->emit_call(this->get_printf(), { formatter, value });

    return {};
  }

  auto LLVMObjectEmitterVisitor::visitReturnStatement(FridayParser::ReturnStatementContext *ctx) -> any {
    this->visitChildren(ctx);

    Value value = $(ctx->expression()).value;
    if(value.type()->to_llvm_type() == LLVM.get_void_type()) {
      LLVM.builder().CreateRetVoid();
    } else LLVM.builder().CreateRet(this->emit_value(value));

    return {};
  }

  auto LLVMObjectEmitterVisitor::visitExpressionStatement(FridayParser::ExpressionStatementContext *ctx) -> any {
    this->visitChildren(ctx);
    return {};
  }

  auto LLVMObjectEmitterVisitor::visitIfStatement(FridayParser::IfStatementContext *ctx) -> any {
    llvm::Function* function = LLVM.builder().GetInsertBlock()->getParent();

    llvm::BasicBlock* mergeBlock = llvm::BasicBlock::Create(LLVM.context(), "if.merge");

    auto group = views::zip(
      views::indices(ctx->conditions.size()), 
      ctx->conditions, 
      ctx->scopes
    );

    for(auto [i, conditionContext, thenContext] : group) {
      this->visit(conditionContext);

      llvm::Value* conditionValue = this->emit_value($(conditionContext).value);
      llvm::BasicBlock* thenBlock = llvm::BasicBlock::Create(LLVM.context(), "if.then");

      llvm::BasicBlock* nextBlock = nullptr;
      if(i+1 < ctx->conditions.size()) {
        nextBlock = llvm::BasicBlock::Create(LLVM.context(), "elif.condition");
      } else if(ctx->elseStatement != nullptr) {
        nextBlock = llvm::BasicBlock::Create(LLVM.context(), "else.body");
      } else nextBlock = mergeBlock;

      LLVM.builder().CreateCondBr(conditionValue, thenBlock, nextBlock);

      function->insert(function->end(), thenBlock);
      LLVM.builder().SetInsertPoint(thenBlock);
      this->visit(thenContext);

      if(LLVM.builder().GetInsertBlock()->getTerminator() == nullptr) {
        LLVM.builder().CreateBr(mergeBlock);
      }

      if(nextBlock != mergeBlock) {
        function->insert(function->end(), nextBlock);
        LLVM.builder().SetInsertPoint(nextBlock);
      }
    }

    if(ctx->elseStatement != nullptr) {
      this->visit(ctx->elseStatement);

      if(LLVM.builder().GetInsertBlock()->getTerminator() == nullptr) {
        LLVM.builder().CreateBr(mergeBlock);
      }
    }

    function->insert(function->end(), mergeBlock);
    LLVM.builder().SetInsertPoint(mergeBlock);

    return {};
  }

  auto LLVMObjectEmitterVisitor::visitForStatement(FridayParser::ForStatementContext *ctx) -> any {
    llvm::Function* func = LLVM.builder().GetInsertBlock()->getParent();

    llvm::BasicBlock* condBlock = llvm::BasicBlock::Create(LLVM.context(), "for.cond", func);
    llvm::BasicBlock* whereBlock = nullptr;

    if(ctx->WHERE() != nullptr) {
      whereBlock = llvm::BasicBlock::Create(LLVM.context(), "for.where", func);
    }

    llvm::BasicBlock* bodyBlock = llvm::BasicBlock::Create(LLVM.context(), "for.body", func);
    llvm::BasicBlock* incrBlock = llvm::BasicBlock::Create(LLVM.context(), "for.incr", func);
    llvm::BasicBlock* afterBlock = llvm::BasicBlock::Create(LLVM.context(), "for.after", func);


    if(ctx->varname != nullptr) {
      // Indexed for loop
      
      this->visit(ctx->from);
      llvm::Value* lowerBound = this->emit_value($(ctx->from).value);

      this->visit(ctx->to);
      llvm::Value* upperBound = this->emit_value($(ctx->to).value);

      llvm::Value* indexAlloca = this->emit_alloca(Type::get_int_type()->to_llvm_type());
      LLVM.builder().CreateStore(lowerBound, indexAlloca);

      ISymbol* symbol = $(ctx->scope).scope->retrieve_if(
        ctx->varname->getText(), 
        &Variable::is_variable
      );
      this->bind(symbol, indexAlloca);

      LLVM.builder().CreateBr(condBlock);
      LLVM.builder().SetInsertPoint(condBlock);

      llvm::Value* index = LLVM.builder().CreateLoad(Type::get_int_type()->to_llvm_type(), indexAlloca);
      llvm::Value* condition = ctx->DOTDOT() ? 
        LLVM.builder().CreateICmpSLT(index, upperBound)
      : LLVM.builder().CreateICmpSLE(index, upperBound);

      LLVM.builder().CreateCondBr(condition, whereBlock ? whereBlock : bodyBlock, afterBlock);

      if(whereBlock != nullptr) {
        LLVM.builder().SetInsertPoint(whereBlock);

        this->visit(ctx->filterExpr);
        llvm::Value* filterExpr = this->emit_value($(ctx->filterExpr).value);
        LLVM.builder().CreateCondBr(filterExpr, bodyBlock, incrBlock);
      }

      LLVM.builder().SetInsertPoint(bodyBlock);
      this->visit(ctx->scope);
      if(LLVM.builder().GetInsertBlock()->getTerminator() == nullptr) {
        LLVM.builder().CreateBr(incrBlock);
      }

      LLVM.builder().SetInsertPoint(incrBlock);
      
      llvm::Value* nextIdx = LLVM.builder().CreateAdd(index, LLVM.builder().getInt64(1));
      LLVM.builder().CreateStore(nextIdx, indexAlloca);
      LLVM.builder().CreateBr(condBlock);
      
      LLVM.builder().SetInsertPoint(afterBlock);
    } else {
      // Slice for loop

    }

    return {};
  }

  auto LLVMObjectEmitterVisitor::visitWhileStatement(FridayParser::WhileStatementContext *ctx) -> any {
    llvm::Function* func = LLVM.builder().GetInsertBlock()->getParent();

    llvm::BasicBlock* conditionBlock = llvm::BasicBlock::Create(LLVM.context(), ".while-condition", func);
    llvm::BasicBlock* bodyBlock = llvm::BasicBlock::Create(LLVM.context(), ".while-body", func);
    llvm::BasicBlock* afterBlock = llvm::BasicBlock::Create(LLVM.context(), ".while-after", func);

    LLVM.builder().CreateBr(conditionBlock);
    LLVM.builder().SetInsertPoint(conditionBlock);

    this->visit(ctx->condition);
    llvm::Value* condition = this->emit_value($(ctx->condition).value);

    LLVM.builder().CreateCondBr(condition, bodyBlock, afterBlock);

    LLVM.builder().SetInsertPoint(bodyBlock);
    this->visit(ctx->scope);

    if(LLVM.builder().GetInsertBlock()->getTerminator() == nullptr) {
      LLVM.builder().CreateBr(conditionBlock);
    }

    LLVM.builder().SetInsertPoint(afterBlock);

    return {};
  }

  auto LLVMObjectEmitterVisitor::visitDeclarationStatement(FridayParser::DeclarationStatementContext *ctx) -> any {
    this->visitChildren(ctx);

    // Get the initializer value
    llvm::Value* initializer = this->emit_value($(ctx->initializer).value);

    // Get the type
    llvm::Type* type = initializer->getType();

    // Get the symbol
    ISymbol* symbol = dynamic_cast<ISymbol*>($(ctx).variable);

    llvm::AllocaInst* alloca = nullptr;

    // Get the alloca
    if(not this->has_binding(symbol)) {
      // Emit the alloca if the variable was not previously bound
      alloca = this->emit_alloca(type);

      // Bind the symbol to its runtime value
      this->bind(symbol, llvm::cast<llvm::Value>(alloca));

      // Or else get the variable-bound alloca
    } else alloca = llvm::cast<llvm::AllocaInst>(this->query(symbol));
      
    // Assign the value to the object
    LLVM.builder().CreateStore(initializer, alloca);
    
    return {};
  }

  auto LLVMObjectEmitterVisitor::visitDeferStatement(FridayParser::DeferStatementContext *ctx) -> any {
    if(this->M_deferred != nullptr) {
      this->M_deferred->push(ctx->statement());
    } else this->visit(ctx->statement());

    return {};
  }

  auto LLVMObjectEmitterVisitor::visitScopeStatement(FridayParser::ScopeStatementContext *ctx) -> any {
    stack<FridayParser::StatementContext*> deferred { };
    stack<FridayParser::StatementContext*>* previous = this->M_deferred;

    this->M_deferred = &deferred;
    this->visitChildren(ctx);
    
    while(not deferred.empty()) {
      auto stmt = deferred.top();
      this->visit(stmt);
      deferred.pop();
    }

    this->M_deferred = previous;

    return {};
  }

  auto LLVMObjectEmitterVisitor::visitSyntacticalScope(FridayParser::SyntacticalScopeContext *ctx) -> any {
    stack<FridayParser::StatementContext*> deferred { };
    stack<FridayParser::StatementContext*>* previous = this->M_deferred;
    
    this->M_deferred = &deferred;
    this->visitChildren(ctx);
    
    while(not deferred.empty()) {
      auto stmt = deferred.top();
      this->visit(stmt);
      deferred.pop();
    }

    this->M_deferred = previous;

    return {};
  }

  auto LLVMObjectEmitterVisitor::visitBasicBlock(FridayParser::BasicBlockContext *ctx) -> any {
    stack<FridayParser::StatementContext*> deferred { };
    stack<FridayParser::StatementContext*>* previous = this->M_deferred;
    
    this->M_deferred = &deferred;
    this->visitChildren(ctx);
    
    while(not deferred.empty()) {
      auto stmt = deferred.top();
      this->visit(stmt);
      deferred.pop();
    }

    this->M_deferred = previous;
    return {};
  }

  auto LLVMObjectEmitterVisitor::visitTrailingBlock(FridayParser::TrailingBlockContext *ctx) -> any {
    this->visitChildren(ctx);
    
    Value value = $(ctx->expression()).value;
    if(value.type()->to_llvm_type() == LLVM.get_void_type()) {
      LLVM.builder().CreateRetVoid();
    } else LLVM.builder().CreateRet(this->emit_value(value));

    return {};
  }


}