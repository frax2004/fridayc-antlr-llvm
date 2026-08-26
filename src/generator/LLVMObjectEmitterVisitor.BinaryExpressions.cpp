#include <fridayc.hpp>


namespace friday::inline api {
  auto LLVMObjectEmitterVisitor::visitExplicitCastExpression(FridayParser::ExplicitCastExpressionContext *ctx) -> any {
    (void)ctx;
    return {};
  }

  auto LLVMObjectEmitterVisitor::visitBinaryExpression(FridayParser::BinaryExpressionContext *ctx) -> any {
    this->visitChildren(ctx);

    // Get the operands values
    llvm::Value* lhs = this->emit_value($(ctx->left).value);
    llvm::Value* rhs = this->emit_value($(ctx->right).value);

    // Get the operator
    llvm::Function* _operator = llvm::cast<llvm::Function>(this->query(dynamic_cast<ISymbol*>($(ctx)._operator)));

    // Emit the call to the operator
    llvm::CallInst* invokeResult = this->emit_call(_operator, { lhs, rhs });

    Value& value = $(ctx).value;
    value = Value::from_rvalue(value.type(), llvm::cast<llvm::Value>(invokeResult));

    return {};
  }

  auto LLVMObjectEmitterVisitor::visitAssignmentExpression(FridayParser::AssignmentExpressionContext *ctx) -> any {
    (void)ctx;
    return {};
  }

  auto LLVMObjectEmitterVisitor::visitSubscriptExpression(FridayParser::SubscriptExpressionContext *ctx) -> any {
    (void)ctx;
    return {};
  }

  auto LLVMObjectEmitterVisitor::visitCallExpression(FridayParser::CallExpressionContext *ctx) -> any {
    this->visitChildren(ctx);

    // Emit the arguments
    auto args = ctx->args
    | views::transform([](FridayParser::ExpressionContext* expr) { return $(expr).value; })
    | views::transform([this](Value val) { return this->emit_value(val); })
    | ranges::to<vector>();

    // Create the callee data
    llvm::FunctionCallee callee {};

    // Get the caller as a known function
    if(auto caller = $(ctx).caller; caller != nullptr) {
      callee = llvm::cast<llvm::Function>(this->query(dynamic_cast<ISymbol*>(caller)));
    } else {
      // The caller is a function pointer
      Value funcPtr = $(ctx->func).value;

      callee = llvm::FunctionCallee{
        llvm::cast<llvm::FunctionType>(
          FunctionType::to_function(funcPtr.type())->to_llvm_signature_type()
        ),
        this->emit_value(funcPtr)
      };
    }

    // Call the function
    llvm::CallInst* invokeResult = this->emit_call(callee, args);

    Value& val = $(ctx).value;
    val = Value::from_rvalue(val.type(), llvm::cast<llvm::Value>(invokeResult));

    return {};
  }

  auto LLVMObjectEmitterVisitor::visitMemberAccessExpression(FridayParser::MemberAccessExpressionContext *ctx) -> any {
    (void)ctx;
    return {};
  }

  
}