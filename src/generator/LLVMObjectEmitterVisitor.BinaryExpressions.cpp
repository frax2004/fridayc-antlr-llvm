#include <fridayc.hpp>


namespace friday::inline api {

  auto LLVMObjectEmitterVisitor::coerce_value(Value const& value) -> llvm::Value* {
    llvm::Value* result = this->emit_value(value);

    llvm::Type* abiType = value.type()->to_llvm_abi_type();
    llvm::Type* storageType = value.type()->to_llvm_type();

    if(abiType != storageType) {
      llvm::Value* addr = value.to_llvm_value();

      if(value.is(ValueCategory::RVALUE)) {
        llvm::Value* temp = this->emit_alloca(storageType);
        LLVM.builder().CreateStore(result, temp);
        addr = temp;
      }
      return LLVM.builder().CreateLoad(abiType, addr);
    } else return result;
  }

  auto LLVMObjectEmitterVisitor::visitExplicitCastExpression(FridayParser::ExplicitCastExpressionContext *ctx) -> any {
    this->visitChildren(ctx);

    llvm::Value* object = this->emit_value($(ctx->expr).value);
    llvm::Type* target = $(ctx->target).type->to_llvm_type();

    llvm::Value* casted = LLVM.builder().CreateCast($(ctx).castOp, object, target);

    Value& value = $(ctx).value;
    value = Value::from_rvalue(value.type(), casted);

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
    this->visitChildren(ctx);

    Value expr = $(ctx->right).value;
    Value lvalue = $(ctx->left).value;

    // Get the store address
    llvm::Value* ptr = lvalue.to_llvm_value();

    // Emit the right operand
    llvm::Value* rhs = this->emit_value(expr);

    if(ctx->binaryOperator->getType() == FridayParser::ASSIGN) {
      LLVM.builder().CreateStore(rhs, ptr);
    } else {
      // Emit the left operand
      llvm::Value* lhs = this->emit_value(lvalue);

      // Get the operator
      llvm::Function* _operator = llvm::cast<llvm::Function>(this->query(dynamic_cast<ISymbol*>($(ctx)._operator)));

      // Emit the call to the operator
      llvm::CallInst* invokeResult = this->emit_call(_operator, { lhs, rhs });

      // Store the result
      LLVM.builder().CreateStore(invokeResult, ptr);
    }

    $(ctx).value = lvalue;

    return {};
  }

  auto LLVMObjectEmitterVisitor::visitSubscriptExpression(FridayParser::SubscriptExpressionContext *ctx) -> any {
    this->visitChildren(ctx);

    Value array = $(ctx->array).value;
    Value idx = $(ctx->index).value;

    llvm::Value* index = this->emit_value(idx);
    llvm::Value* slicePtr = array.to_llvm_value();
    llvm::Type* sliceType = array.type()->to_llvm_type();
    
    if(array.is(ValueCategory::RVALUE)) {
      llvm::Value* temp = this->emit_alloca(sliceType);
      LLVM.builder().CreateStore(slicePtr, temp);
      slicePtr = temp;
    }
    
    llvm::Value* ptrFieldRef = LLVM.builder().CreateStructGEP(sliceType, slicePtr, 0);
    
    llvm::Type* rawPtrType = LLVM.get_pointer_type();
    llvm::Value* rawArrayPtr = LLVM.builder().CreateLoad(rawPtrType, ptrFieldRef);
    
    ArrayType* arrayType = ArrayType::to_array(array.type());

    llvm::Type* elementType = arrayType->get_element_type()->to_llvm_type();
    llvm::Value* lvalue = LLVM.builder().CreateInBoundsGEP(elementType, rawArrayPtr, index);

    Value& value = $(ctx).value;
    value = Value::from_lvalue(value.type(), nullptr, lvalue);

    return {};
  }

  auto LLVMObjectEmitterVisitor::visitCallExpression(FridayParser::CallExpressionContext *ctx) -> any {
    this->visitChildren(ctx);

    // Emit the arguments
    vector<llvm::Value*> args = {};

    // Create the callee data
    llvm::FunctionCallee callee {};
    
    Function* caller = $(ctx).caller;

    // Get the caller as a known function
    if(caller != nullptr) {
      callee = llvm::FunctionCallee {
        llvm::cast<llvm::FunctionType>(
          FunctionType::to_function(caller->get_type())->to_llvm_signature_type(caller->is_native())
        ),
        llvm::cast<llvm::Function>(this->query(dynamic_cast<ISymbol*>(caller)))
      };

      args = ctx->args
      | views::transform([](FridayParser::ExpressionContext* expr) { return $(expr).value; })
      | views::transform([this, isNative = caller->is_native()](Value val) { 
        return isNative ? this->coerce_value(val) : this->emit_value(val); 
      })
      | ranges::to<vector>();

      if(caller->is_nonstatic_method()) {
        // MemberAccessExpressionContext
        auto MAEC = dynamic_cast<FridayParser::MemberAccessExpressionContext*>(ctx->func);
        Value object = $(MAEC->object).value;

        Type* objectType = object.type();
        Type* firstType = caller->get_param(0).second;
        bool objectIsPointer = objectType->is_pointer_type();
        bool methodWantsPointer = firstType->is_pointer_type();

        llvm::Value* self = nullptr;

        if(objectIsPointer == methodWantsPointer) {
          // Forward this either as value or as pointer
          self = this->emit_value(object);
        } else if(objectIsPointer and not methodWantsPointer) {
          // auto dereference (implies a copy)
          
          // Get the pointer
          llvm::Value* pointer = this->emit_value(object);

          // Get the llvm type of the struct
          llvm::Type* type = firstType->to_llvm_type();

          // Load the value into a register or the stack
          self = LLVM.builder().CreateLoad(type, pointer);
        } else if(not objectIsPointer and methodWantsPointer) {
          // auto reference (possible materialization)

          if(object.is(ValueCategory::LVALUE)) {
            // Forward the alloca
            self = object.to_llvm_value();
          } else {
            // Get the llvm type of the struct
            llvm::Type* llvmType = objectType->to_llvm_type();

            // Materialize the value into a temporary address
            self = this->emit_alloca(llvmType);

            // Copy the value into the temporary address
            LLVM.builder().CreateStore(object.to_llvm_value(), self);
          }
        }

        // Insert the self 
        args.insert(args.begin(), self);
      }
    } else {
      // TODO when allowing function pointers, make sure to check if the function pointing to is native or not
      args = ctx->args
      | views::transform([](FridayParser::ExpressionContext* expr) { return $(expr).value; })
      | views::transform([this](Value val) { return this->emit_value(val); })
      | ranges::to<vector>();

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

    Type* retType = caller != nullptr ? caller->get_return_type() : $(ctx).value.type();
    llvm::Value* unwrappedResult = invokeResult;

    if(caller != nullptr and caller->is_native() and retType->is_aggregate_type()) {
      u64 size = retType->size();

      if(0 < size and size <= 8) {
        llvm::Type* aggregateType = retType->to_llvm_type();
        auto tempAlloca = this->emit_alloca(aggregateType);

        tempAlloca->setAlignment(llvm::Align(8));
        LLVM.builder().CreateStore(invokeResult, tempAlloca);

        unwrappedResult = tempAlloca;
      }
    }

    Value& val = $(ctx).value;
    val = Value::from_rvalue(val.type(), unwrappedResult);

    return {};
  }

  auto LLVMObjectEmitterVisitor::visitMemberAccessExpression(FridayParser::MemberAccessExpressionContext *ctx) -> any {
    this->visitChildren(ctx);

    /// Auto reference semantics
    /// (object: *T).field
    /// (object: T).field

    /// (object: *T).method(this: *T)
    /// (object: *T).method(this: T)
    /// (object: T).method(this: *T)
    /// (object: T).method(this: T)

    Value object = $(ctx->object).value;
    Value& accessed = $(ctx).value;

    if(accessed.holds(Value::Kind::STRUCT)) {
      // Nothing
    } else if(accessed.holds(Value::Kind::OVERLOAD)) {
      // Nothing
    } else if(auto asField = accessed.unwrap<pair<Variable*, llvm::Value*>>()) {
      // Get the field symbol
      Variable* symbol = asField->first;
      llvm::Type* llvmStruct = nullptr;
      llvm::Value* structPtr = nullptr;
      Struct* structType = nullptr;

      // If the object's type is pointer-to-struct then use the pointer directly (auto dereference)
      if(auto pointerToStruct = PointerType::to_pointer(object.type())) {
        structType = Struct::to_struct_type(pointerToStruct->get_pointed_type());
        structPtr = this->emit_value(object);
        llvmStruct = pointerToStruct->get_pointed_type()->to_llvm_type();
      } else {
        // Otherwise, direct access if an lvalue or alloca from register to stack and get the pointer if rvalue
        structType = Struct::to_struct_type(object.type());
        structPtr = object.to_llvm_value();
        llvmStruct = structType->to_llvm_type();

        if(object.is(ValueCategory::RVALUE)) {
          llvm::Value* temp = this->emit_alloca(llvmStruct);
          LLVM.builder().CreateStore(structPtr, temp);
          structPtr = temp;
        }
      }

      u64 fieldIndex = structType->get_field_index(symbol->get_qualified_id());
      llvm::Value* fieldPtr = LLVM.builder().CreateStructGEP(llvmStruct, structPtr, fieldIndex);
      accessed = Value::from_lvalue(accessed.type(), symbol, fieldPtr);
    } else throw RuntimeError{"Internal Error."};

    return {};
  }

}