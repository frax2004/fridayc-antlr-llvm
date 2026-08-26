#include <fridayc.hpp>


namespace friday::inline api {
  LLVMObjectEmitterVisitor::LLVMObjectEmitterVisitor(CompilationContext& ctx)
    : StaticAnalyzer { ctx }
  {}

  auto LLVMObjectEmitterVisitor::emit_builtins() -> void {
    (void)this->get_printf();

    auto builtins = Namespace::get_builtins()
    | views::filter(&Overload::is_overload)
    | views::transform(&Overload::to_overload)
    | views::transform(&Overload::get_instances)
    | views::join;

    for(auto func : builtins) {
      this->bind(
        dynamic_cast<ISymbol*>(func),
        this->emit_function(
          func, 
          llvm::GlobalValue::LinkageTypes::ExternalLinkage, 
          &Function::get_mangled_id
        )
      );
    }
  }

  auto LLVMObjectEmitterVisitor::setup() -> void {
    this->emit_builtins();
    this->emit_native_functions();
    this->emit_functions();
  }

  auto LLVMObjectEmitterVisitor::emit_function(Function* func, llvm::GlobalValue::LinkageTypes linkage, function<string(Function*)> get_name) -> llvm::Value* {
    return llvm::dyn_cast<llvm::Value>(
      llvm::Function::Create(
        llvm::cast<llvm::FunctionType>(FunctionType::to_function(func->get_type())->to_llvm_signature_type()),
        linkage,
        get_name(func),
        LLVM.module()
      )
    );
  }

  auto LLVMObjectEmitterVisitor::emit_functions() -> void {
    auto functions = Function::instances()
    | views::filter(&Function::is_non_native);

    for(auto func : functions) {
      this->bind(
        dynamic_cast<ISymbol*>(func), 
        this->emit_function(
          func,
          llvm::GlobalValue::LinkageTypes::ExternalLinkage,
          &Function::get_mangled_id
        )
      );
    }
  }

  auto LLVMObjectEmitterVisitor::emit_native_functions() -> void {
    auto non_builtin = [this](Function* func) {
      return not this->has_binding(dynamic_cast<ISymbol*>(func));
    };

    auto functions = Function::instances()
    | views::filter(non_builtin)
    | views::filter(&Function::is_native);

    for(auto func : functions) {
      this->bind(
        dynamic_cast<ISymbol*>(func), 
        this->emit_function(
          func,
          llvm::GlobalValue::LinkageTypes::ExternalLinkage,
          &Function::get_qualified_id
        )
      );
    }
  }

  auto LLVMObjectEmitterVisitor::emit_alloca(llvm::Type* type, llvm::Value* arraySize) -> llvm::AllocaInst* {
    // Save the current block
    llvm::BasicBlock* currentBlock = LLVM.builder().GetInsertBlock();

    // Save the current instruction
    llvm::BasicBlock::iterator currentInst = LLVM.builder().GetInsertPoint();

    // Get the current function
    llvm::Function* currentFunc = currentBlock->getParent();

    // Get the entry block (the alloca block)
    llvm::BasicBlock& allocaBlock = currentFunc->getEntryBlock();

    // The last instruction of an alloca block should always be an unconditional branch to the entry block
    assert(allocaBlock.getTerminator() != nullptr && "Alloca block does not end with an unconditional branch terminator");

    // Set the insertion point between the last alloca and the unconditional branch
    LLVM.builder().SetInsertPoint(allocaBlock.getTerminator());

    // Perform the alloca
    llvm::AllocaInst* alloca = LLVM.builder().CreateAlloca(type, arraySize);

    // Restore the current block
    LLVM.builder().SetInsertPoint(currentBlock, currentInst);

    return alloca;
  }

  auto LLVMObjectEmitterVisitor::emit_call(llvm::Function* func, llvm::ArrayRef<llvm::Value*> args) -> llvm::CallInst* {
    auto callee = llvm::FunctionCallee{ func->getFunctionType(), llvm::cast<llvm::Value>(func) };
    return LLVM.builder().CreateCall(callee, args);
  }

  auto LLVMObjectEmitterVisitor::emit_call(llvm::FunctionCallee callee, llvm::ArrayRef<llvm::Value*> args) -> llvm::CallInst* {
    return LLVM.builder().CreateCall(callee, args);
  }

  auto LLVMObjectEmitterVisitor::emit_value(Value value) -> llvm::Value* {
    if(value.is(ValueCategory::ILLEGAL)) throw RuntimeError{"Internal Error"};

    llvm::Value* val = value.to_llvm_value();
    llvm::Type* type = value.type()->to_llvm_type();

    if(value.is(ValueCategory::RVALUE)) {
      if(val->getType()->isPointerTy() and not PointerType::is_pointer(value.type())) {
        return llvm::cast<llvm::Value>(LLVM.builder().CreateLoad(type, val));
      } else return val;
    } else return LLVM.builder().CreateLoad(type, val);
  }

  auto LLVMObjectEmitterVisitor::query(ISymbol* symbol) -> llvm::Value* {
    return this->M_values.at(symbol);
  }

  auto LLVMObjectEmitterVisitor::bind(ISymbol* symbol, llvm::Value* value) -> void {
    this->M_values[symbol] = value;
  }

  auto LLVMObjectEmitterVisitor::has_binding(ISymbol* symbol) const -> bool {
    return this->M_values.contains(symbol);
  }

  auto LLVMObjectEmitterVisitor::on_unit_begin(TranslationUnit& unit) -> void {
    (void)unit;
  }
  
  auto LLVMObjectEmitterVisitor::on_unit_end(TranslationUnit& unit) -> void {
    (void)unit;
  }
  
  auto LLVMObjectEmitterVisitor::get_byte() -> llvm::Type* {
    return dynamic_cast<Type*>(Namespace::get_global_namespace()->find_struct("byte"))->to_llvm_type();
  }

  auto LLVMObjectEmitterVisitor::get_int() -> llvm::Type* {
    return dynamic_cast<Type*>(Namespace::get_global_namespace()->find_struct("int"))->to_llvm_type();
  }

  auto LLVMObjectEmitterVisitor::get_bool() -> llvm::Type* {
    return dynamic_cast<Type*>(Namespace::get_global_namespace()->find_struct("bool"))->to_llvm_type();
  }

  auto LLVMObjectEmitterVisitor::get_void() -> llvm::Type* {
    return dynamic_cast<Type*>(Namespace::get_global_namespace()->find_struct("void"))->to_llvm_type();
  }

  auto LLVMObjectEmitterVisitor::get_voidptr() -> llvm::Type* {
    auto Void = dynamic_cast<Type*>(Namespace::get_global_namespace()->find_struct("void"));
    return PointerType::get(*Void, 1)->to_llvm_type();
  }

  auto LLVMObjectEmitterVisitor::get_float() -> llvm::Type* {
    return dynamic_cast<Type*>(Namespace::get_global_namespace()->find_struct("float"))->to_llvm_type();
  }

  auto LLVMObjectEmitterVisitor::get_printf() -> llvm::Function* {
    static llvm::Function* S_printf = llvm::Function::Create(
      llvm::FunctionType::get(
        llvm::Type::getInt32Ty(LLVM.context()),
        llvm::PointerType::get(LLVM.context(), 0),
        true
      ),
      llvm::GlobalValue::LinkageTypes::ExternalLinkage,
      "printf",
      LLVM.module()
    );

    return S_printf;
  }
}
