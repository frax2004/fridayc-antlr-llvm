#include <LLVMObjectEmitterVisitor.hpp>
#include <OperationNotSupportedError.hpp>
#include <ErrorType.hpp>
#include <PointerType.hpp>
#include <ArrayType.hpp>

namespace friday::inline api::inline pipeline {
  auto LLVMObjectEmitterVisitor::visitFloatLiteralExpression(FridayParser::FloatLiteralExpressionContext *ctx) -> any {
    const f64 x = stod(ctx->getText());

    const auto value = llvm::ConstantFP::get(
      ctx->value.get_type()->to_llvm_type(this->comp_context().get_llvm_context()), 
      x
    );

    return {};
  }

  auto LLVMObjectEmitterVisitor::visitArrayLiteralExpression(FridayParser::ArrayLiteralExpressionContext *ctx) -> any {

    return {};
  }

  auto LLVMObjectEmitterVisitor::visitIntLiteralExpression(FridayParser::IntLiteralExpressionContext *ctx) -> any {

    return {};
  }

  auto LLVMObjectEmitterVisitor::visitBoolLiteralExpression(FridayParser::BoolLiteralExpressionContext *ctx) -> any {

    return {};
  }

  auto LLVMObjectEmitterVisitor::visitCharLiteralExpression(FridayParser::CharLiteralExpressionContext *ctx) -> any {

    return {};
  }

  auto LLVMObjectEmitterVisitor::visitNullLiteralExpression(FridayParser::NullLiteralExpressionContext *ctx) -> any {

    return {};
  }

  auto LLVMObjectEmitterVisitor::visitIdentifierExpression(FridayParser::IdentifierExpressionContext *ctx) -> any {

    return {};
  }

  auto LLVMObjectEmitterVisitor::visitStringLiteralExpression(FridayParser::StringLiteralExpressionContext *ctx) -> any {

    return {};
  }


}