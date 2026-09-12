#include <fridayc.hpp>


namespace friday::inline api {
  auto LLVMObjectEmitterVisitor::visitArrayLiteralExpression(FridayParser::ArrayLiteralExpressionContext *ctx) -> any {
    this->visitChildren(ctx);

    // Get the values
    vector<llvm::Value*> values = ctx->values
    | views::transform([](FridayParser::ExpressionContext* expr) { return $(expr).value; })
    | views::transform([this](Value value) { return this->emit_value(value); })
    | ranges::to<vector>();

    // Get the struct { T*, int } type
    ArrayType* sliceType = ArrayType::to_array($(ctx).value.type());

    // Get the element type
    llvm::Type* elementType = sliceType->get_element_type()->to_llvm_type();

    llvm::Value* arraySize = LLVM.builder().getInt64(values.size());

    // Get the array type
    llvm::ArrayType* arrayType = llvm::ArrayType::get(elementType, values.size());

    // Allocate the stack array
    llvm::AllocaInst* arrayInst = this->emit_alloca(arrayType, nullptr);

    // Store each element into the array
    for(u64 i : views::iota(0ULL, values.size())) {
      // Get the index
      llvm::Value* indices[] = {
        LLVM.builder().getInt64(0),
        LLVM.builder().getInt64(i)
      };
      
      // Get the element pointer (array + offset)
      llvm::Value* elementRef = LLVM.builder().CreateInBoundsGEP(arrayType, arrayInst, indices);

      // Store the value into the element pointer
      LLVM.builder().CreateStore(values[i], elementRef);
    }

    // Allocate the slice
    llvm::AllocaInst* sliceInst = this->emit_alloca(sliceType->to_llvm_type());
    
    // Get the fields pointers
    llvm::Value* ptrField = LLVM.builder().CreateStructGEP(sliceType->to_llvm_type(), sliceInst, 0);
    llvm::Value* lenField = LLVM.builder().CreateStructGEP(sliceType->to_llvm_type(), sliceInst, 1);
    
    llvm::Value* zeroIndices[] = { LLVM.builder().getInt32(0), LLVM.builder().getInt32(0) };
    llvm::Value* rawDataPtr = LLVM.builder().CreateInBoundsGEP(arrayType, arrayInst, zeroIndices);

    // Store the array pointer and the length
    LLVM.builder().CreateStore(rawDataPtr, ptrField);
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