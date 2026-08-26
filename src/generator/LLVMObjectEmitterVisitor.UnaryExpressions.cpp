#include <fridayc.hpp>



namespace friday::inline api {
  
  auto LLVMObjectEmitterVisitor::visitNewExpression(FridayParser::NewExpressionContext *ctx) -> any {
    (void)ctx;

    auto toIndexedPair = [](auto pair) { 
      return make_pair(
        get<1>(pair), 
        static_cast<u64>(get<0>(pair))
      ); 
    };

    // Visit the children expressions
    this->visitChildren(ctx);

    // Get the struct type
    Struct* type = dynamic_cast<Struct*>($(ctx).value.type());

    // Map each field name to its index
    map<string, u64> fieldIndex = type->get_fields()
    | views::transform(&Variable::get_qualified_id)
    | views::enumerate
    | views::transform(toIndexedPair)
    | ranges::to<map>();

    // Get the actual llvm struct type
    llvm::Type* llvmType = type->to_llvm_type();

    // Zip field names with their initializer values
    auto namedInitializers = views::zip(
      ctx->fields 
      | views::transform(&ant::Token::getText),
      ctx->initializers
      | views::transform([](FridayParser::ExpressionContext* expr) { return $(expr).value; })
    );
    
    // Allocate the struct into the stack
    llvm::AllocaInst* structInst = this->emit_alloca(type->to_llvm_type());

    // Store each value into the correspondent field pointer of the struct
    for(auto [name, initializer] : namedInitializers) {
      // Get the index of the field by name
      u64 index = fieldIndex.at(name);

      // Get the field pointer
      llvm::Value* fieldPtr = LLVM.builder().CreateStructGEP(
        llvmType,
        llvm::cast<llvm::Value>(structInst),
        index
      );

      // Emit the initializer value
      llvm::Value* fieldValue = this->emit_value(initializer);

      // Store the value into the field pointer
      LLVM.builder().CreateStore(fieldValue, fieldPtr);
    }

    // Update the llvm value for this expression
    Value& value = $(ctx).value;
    value = Value::from_rvalue(type, llvm::cast<llvm::Value>(structInst));

    return {};
  }

  auto LLVMObjectEmitterVisitor::visitUnaryPrefixExpression(FridayParser::UnaryPrefixExpressionContext *ctx) -> any {
    assert(
      ctx->unaryOperator->getType() != FridayParser::AMPERSAND
      and ctx->unaryOperator->getType() != FridayParser::STAR
      and "Reference and Dereference operators not yet implemented"
    );

    this->visitChildren(ctx);

    // Get the operand value
    llvm::Value* operand = this->emit_value($(ctx->operand).value);

    // Get the operator
    llvm::Function* _operator = llvm::cast<llvm::Function>(this->query(dynamic_cast<ISymbol*>($(ctx)._operator)));

    // Emit the call to the operator
    llvm::CallInst* invokeResult = this->emit_call(_operator, { operand });

    Value& value = $(ctx).value;
    value = Value::from_rvalue(value.type(), llvm::cast<llvm::Value>(invokeResult));

    return {};
  }

  auto LLVMObjectEmitterVisitor::visitUnaryPostfixExpression(FridayParser::UnaryPostfixExpressionContext *ctx) -> any {

    this->visitChildren(ctx);

    // Get the operand value
    llvm::Value* operand = this->emit_value($(ctx->operand).value);

    // Get the operator
    llvm::Function* _operator = llvm::cast<llvm::Function>(this->query(dynamic_cast<ISymbol*>($(ctx)._operator)));

    // Emit the call to the operator
    llvm::CallInst* invokeResult = this->emit_call(_operator, { operand });

    Value& value = $(ctx).value;
    value = Value::from_rvalue(value.type(), llvm::cast<llvm::Value>(invokeResult));

    return {};
  }

  auto LLVMObjectEmitterVisitor::visitGroupingExpression(FridayParser::GroupingExpressionContext *ctx) -> any {
    this->visitChildren(ctx);
    $(ctx).value = $(ctx->expression()).value;
    return {};
  }

  auto LLVMObjectEmitterVisitor::visitCompTimeUnaryPrefixExpression(FridayParser::CompTimeUnaryPrefixExpressionContext *ctx) -> any {
    (void)ctx;
    return {};
  }

}