#include <fridayc.hpp>

namespace friday::inline api {
  auto LLVMObjectEmitterVisitor::visitFreeFunctionStatement(FridayParser::FreeFunctionStatementContext *ctx) -> any {
    Function* decl = $(ctx).function;
    
    llvm::Function* func = $(ctx).llvm_function = llvm::Function::Create(
      llvm::cast<llvm::FunctionType>(decl->get_type()->to_llvm_type()),
      llvm::GlobalValue::LinkageTypes::ExternalLinkage,
      decl->get_mangled_id(),
      LLVMWrapper::instance().module()
    );

    for(auto&& [i, arg] : func->args() | views::enumerate) {
      arg.setName(decl->get_param_name(i));
    }

    llvm::BasicBlock *BB = llvm::BasicBlock::Create(
      LLVMWrapper::instance().context(),
      "",
      func
    );
    
    LLVMWrapper::instance().builder().SetInsertPoint(BB);
    
    this->visitChildren(ctx);

    if(
      auto currentBlock = LLVMWrapper::instance().builder().GetInsertBlock(); 
      currentBlock != nullptr and (
        currentBlock->empty() 
        or not currentBlock->back().isTerminator()
      )
    ) LLVMWrapper::instance().builder().CreateRetVoid();

    return {};
  }

  auto LLVMObjectEmitterVisitor::visitNativeFunctionStatement(FridayParser::NativeFunctionStatementContext *ctx) -> any {
    Function* decl = $(ctx).function;
    
    llvm::Function* func = $(ctx).llvm_function = llvm::Function::Create(
      llvm::cast<llvm::FunctionType>(decl->get_type()->to_llvm_type()),
      llvm::GlobalValue::LinkageTypes::ExternalLinkage,
      decl->get_mangled_id(),
      LLVMWrapper::instance().module()
    );

    for(auto&& [i, arg] : func->args() | views::enumerate) {
      arg.setName(decl->get_param_name(i));
    }
    return {};
  }

  auto LLVMObjectEmitterVisitor::visitStructStatement(FridayParser::StructStatementContext *ctx) -> any {
    $(ctx).llvm_struct = llvm::cast<llvm::StructType>($(ctx).struct_->to_llvm_type());
    this->visitChildren(ctx);
    return {};
  }

  auto LLVMObjectEmitterVisitor::visitPrintStatement(FridayParser::PrintStatementContext *ctx) -> any {
    this->visitChildren(ctx);

    llvm::Value* str = $(ctx->expression()).value.to_rvalue().value();

    LLVMWrapper::instance().builder().CreateCall(
      llvm::FunctionCallee{
        this->PRINTF()->getFunctionType(),
        llvm::cast<llvm::Value>(this->PRINTF())
      },
      { str },
      "printf"
    );

    return {};
  }

  auto LLVMObjectEmitterVisitor::visitReturnStatement(FridayParser::ReturnStatementContext *ctx) -> any {
    this->visitChildren(ctx);
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
    this->visitChildren(ctx);
    return {};
  }

  auto LLVMObjectEmitterVisitor::visitDeclarationStatement(FridayParser::DeclarationStatementContext *ctx) -> any {
    this->visitChildren(ctx);
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
    return {};
  }


}