#include <LLVMObjectEmitterVisitor.hpp>
#include <OperationNotSupportedError.hpp>
#include <ErrorType.hpp>
#include <PointerType.hpp>
#include <ArrayType.hpp>

namespace friday::inline api::inline pipeline {
  auto LLVMObjectEmitterVisitor::visitFreeFunctionStatement(FridayParser::FreeFunctionStatementContext *ctx) -> any {
    auto decl = ctx->functionDecl.lock();
    
    auto type = llvm::cast<llvm::FunctionType>(
      decl
      ->get_type()
      ->to_llvm_type(this->comp_context().get_llvm_context())
    );

    auto func = llvm::Function::Create(
      type,
      llvm::GlobalValue::LinkageTypes::ExternalLinkage,
      decl->get_mangled_id(),
      *this->current()
    );

    for(auto&& [i, arg] : ranges::subrange(func->arg_begin(), func->arg_end()) | views::enumerate) {
      arg.setName(decl->get_param_name(i));
    }

    llvm::BasicBlock *BB = llvm::BasicBlock::Create(
      this->comp_context().get_llvm_context(), 
      "",
      func
    );

    this->M_builder->SetInsertPoint(BB);
    this->M_builder->CreateRet(nullptr);

    return {};
  }

  auto LLVMObjectEmitterVisitor::visitNativeFunctionStatement(FridayParser::NativeFunctionStatementContext *ctx) -> any {
    this->visitChildren(ctx);
    return {};
  }

  auto LLVMObjectEmitterVisitor::visitStructStatement(FridayParser::StructStatementContext *ctx) -> any {
    this->visitChildren(ctx);
    return {};
  }

  auto LLVMObjectEmitterVisitor::visitPrintStatement(FridayParser::PrintStatementContext *ctx) -> any {
    this->visitChildren(ctx);
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