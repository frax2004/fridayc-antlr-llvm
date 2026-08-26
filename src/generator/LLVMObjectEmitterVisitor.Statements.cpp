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
      if(func->getReturnType() == this->get_void())
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

    // Get the string value
    llvm::Value* str = this->emit_value($(ctx->expression()).value);

    // Call to C printf
    this->emit_call(this->get_printf(), { str });

    return {};
  }

  auto LLVMObjectEmitterVisitor::visitReturnStatement(FridayParser::ReturnStatementContext *ctx) -> any {
    this->visitChildren(ctx);

    Value value = $(ctx->expression()).value;
    if(value.type()->to_llvm_type() == this->get_void()) {
      LLVM.builder().CreateRetVoid();
    } else LLVM.builder().CreateRet(this->emit_value(value));

    return {};
  }

  auto LLVMObjectEmitterVisitor::visitExpressionStatement(FridayParser::ExpressionStatementContext *ctx) -> any {
    this->visitChildren(ctx);
    return {};
  }

  auto LLVMObjectEmitterVisitor::visitIfStatement(FridayParser::IfStatementContext *ctx) -> any {
    this->visitChildren(ctx);
    return {};
  }

  auto LLVMObjectEmitterVisitor::visitForStatement(FridayParser::ForStatementContext *ctx) -> any {
    this->visitChildren(ctx);
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
    this->visitChildren(ctx);
    return {};
  }

  auto LLVMObjectEmitterVisitor::visitScopeStatement(FridayParser::ScopeStatementContext *ctx) -> any {
    this->visitChildren(ctx);
    return {};
  }

  auto LLVMObjectEmitterVisitor::visitSyntacticalScope(FridayParser::SyntacticalScopeContext *ctx) -> any {
    this->visitChildren(ctx);
    return {};
  }

  auto LLVMObjectEmitterVisitor::visitBasicBlock(FridayParser::BasicBlockContext *ctx) -> any {
    this->visitChildren(ctx);
    return {};
  }

  auto LLVMObjectEmitterVisitor::visitTrailingBlock(FridayParser::TrailingBlockContext *ctx) -> any {
    this->visitChildren(ctx);
    
    Value value = $(ctx->expression()).value;
    if(value.type()->to_llvm_type() == this->get_void()) {
      LLVM.builder().CreateRetVoid();
    } else LLVM.builder().CreateRet(this->emit_value(value));

    return {};
  }


}