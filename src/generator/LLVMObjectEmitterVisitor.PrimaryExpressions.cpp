#include <fridayc.hpp>


namespace friday::inline api {
  auto LLVMObjectEmitterVisitor::visitArrayLiteralExpression(FridayParser::ArrayLiteralExpressionContext *ctx) -> any {
    (void)ctx;

    // Get the values
    vector<llvm::Value*> values = ctx->values
    | views::transform([](FridayParser::ExpressionContext* expr) { return $(expr).value; })
    | views::transform([this](Value value) { return this->emit_value(value); })
    | ranges::to<vector>();

    // Get the struct { T*, int } type
    ArrayType* sliceType = ArrayType::to_array($(ctx).value.type());

    // Get the element type
    llvm::Type* elementType = sliceType->get_element_type()->to_llvm_type();

    llvm::Value* arraySize = LLVM.builder().getInt32(values.size());

    // Allocate the stack array
    llvm::AllocaInst* arrayInst = this->emit_alloca(elementType, arraySize);

    // Store each element into the array
    for(u64 i : views::iota(0ULL, values.size())) {
      // Get the index
      llvm::Value* index = LLVM.builder().getInt32(i);
      
      // Get the element pointer (array + offset)
      llvm::Value* elementRef = LLVM.builder().CreateInBoundsGEP(elementType, arrayInst, index);

      // Store the value into the element pointer
      LLVM.builder().CreateStore(values[i], elementRef);
    }

    // Allocate the slice
    llvm::AllocaInst* sliceInst = this->emit_alloca(sliceType->to_llvm_type());

    // Get the fields pointers
    llvm::Value* ptrField = LLVM.builder().CreateStructGEP(sliceType->to_llvm_type(), sliceInst, 0);
    llvm::Value* lenField = LLVM.builder().CreateStructGEP(sliceType->to_llvm_type(), sliceInst, 1);

    // Store the array pointer and the length
    LLVM.builder().CreateStore(arrayInst, ptrField);
    LLVM.builder().CreateStore(arraySize, lenField);

    Value& value = $(ctx).value;
    value = Value::from_rvalue(sliceType, llvm::cast<llvm::Value>(sliceInst));

    return {};
  }

  auto LLVMObjectEmitterVisitor::visitIdentifierExpression(FridayParser::IdentifierExpressionContext *ctx) -> any {
    (void)ctx;
    Value& value = $(ctx).value;

    if(value.holds(Value::Kind::VARIABLE)) {
      Variable* var = value.unwrap<pair<Variable*, llvm::Value*>>()->first;
      value = Value::from_lvalue(
        var->get_type(), 
        var, 
        this->query(dynamic_cast<ISymbol*>(var))
      );
    }

    return {};
  }

}