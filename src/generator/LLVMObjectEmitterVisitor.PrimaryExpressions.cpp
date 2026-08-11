#include <fridayc.hpp>


namespace friday::inline api {

  auto LLVMObjectEmitterVisitor::visitFloatLiteralExpression(FridayParser::FloatLiteralExpressionContext *ctx) -> any {
    Value& value = $(ctx).value;
    value = Value::from_rvalue(
      value.get_type(), 
      llvm::ConstantFP::get(
        value.get_type()->to_llvm_type(),
        value
        .to_constant()
        .and_then(&Constant::to_float)
        .value()
      )
    );

    return {};
  }

  auto LLVMObjectEmitterVisitor::visitArrayLiteralExpression(FridayParser::ArrayLiteralExpressionContext *ctx) -> any {
    (void)ctx;
    return {};
  }

  auto LLVMObjectEmitterVisitor::visitIntLiteralExpression(FridayParser::IntLiteralExpressionContext *ctx) -> any {
    Value& value = $(ctx).value;
    value = Value::from_rvalue(
      value.get_type(), 
      llvm::ConstantInt::getSigned(
        value.get_type()->to_llvm_type(),
        value
        .to_constant()
        .and_then(&Constant::to_int)
        .value()
      )
    );

    return {};
  }

  auto LLVMObjectEmitterVisitor::visitBoolLiteralExpression(FridayParser::BoolLiteralExpressionContext *ctx) -> any {
    Value& value = $(ctx).value;
    value = Value::from_rvalue(
      value.get_type(), 
      llvm::ConstantInt::getBool(
        value.get_type()->to_llvm_type(),
        value
        .to_constant()
        .and_then(&Constant::to_bool)
        .value()
      )
    );

    return {};
  }

  auto LLVMObjectEmitterVisitor::visitCharLiteralExpression(FridayParser::CharLiteralExpressionContext *ctx) -> any {
    Value& value = $(ctx).value;
    value = Value::from_rvalue(
      value.get_type(), 
      llvm::ConstantInt::get(
        value.get_type()->to_llvm_type(),
        value
        .to_constant()
        .and_then(&Constant::to_byte)
        .value()
      )
    );

    return {};
  }

  auto LLVMObjectEmitterVisitor::visitNullLiteralExpression(FridayParser::NullLiteralExpressionContext *ctx) -> any {
    Value& value = $(ctx).value;
    value = Value::from_rvalue(
      value.get_type(), 
      llvm::Constant::getNullValue(value.get_type()->to_llvm_type())
    );

    return {};
  }

  auto LLVMObjectEmitterVisitor::visitStringLiteralExpression(FridayParser::StringLiteralExpressionContext *ctx) -> any {
    Value& value = $(ctx).value;
    value = Value::from_rvalue(
      value.get_type(), 
      LLVMWrapper::instance()
      .builder()
      .CreateGlobalString(
        value
        .to_constant()
        .and_then(&Constant::to_str)
        .value(),
        "",
        0,
        &LLVMWrapper::instance()
        .module()
      )
    );

    return {};
  }
  
  auto LLVMObjectEmitterVisitor::visitIdentifierExpression(FridayParser::IdentifierExpressionContext *ctx) -> any {
    (void)ctx;

    return {};
  }

}