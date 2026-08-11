#include <fridayc.hpp>


namespace friday::inline api {
  unordered_map<void*, void*> LLVMObjectEmitterVisitor::S_builtins { };

  LLVMObjectEmitterVisitor::LLVMObjectEmitterVisitor(CompilationContext& ctx)
    : StaticAnalyzer { ctx }
  {
    this->setup();
  }

  auto LLVMObjectEmitterVisitor::setup() -> void {
    auto to_func_pair = [](Function* func) {
      return make_pair(
        func,
        llvm::Function::Create(
          llvm::cast<llvm::FunctionType>(func->get_type()->to_llvm_type()),
          llvm::GlobalValue::LinkageTypes::ExternalLinkage,
          func->get_mangled_id(),
          LLVMWrapper::instance().module()
        )
      );
    };

    auto to_struct_pair = [](Struct* strct) {
      return make_pair(strct, strct->to_llvm_type());
    };

    auto is_external = [](Function* func) { 
      return func->get_attributes().linkage == Linkage::EXTERNAL; 
    };

    auto builtinFunctions = Namespace::get_global_namespace()->get_symbols()
    | views::filter(&Overload::is_overload)
    | views::transform(&Overload::to_overload)
    | views::transform(&Overload::get_instances)
    | views::join
    | views::filter(is_external)
    | views::transform(to_func_pair);

    auto builtinStructs = Namespace::get_global_namespace()->get_symbols()
    | views::filter(&Struct::is_struct)
    | views::transform(&Struct::to_struct)
    | views::transform(to_struct_pair);

    for(auto [key, value] : builtinFunctions) {
      S_builtins.emplace(
        dynamic_cast<void*>(key),
        static_cast<void*>(value)
      );
    }

    for(auto [key, value] : builtinStructs) {
      S_builtins.emplace(
        dynamic_cast<void*>(key),
        static_cast<void*>(value)
      );
    }

  }

  auto LLVMObjectEmitterVisitor::on_unit_begin(TranslationUnit& unit) -> void {
    (void)unit;
  }
  
  auto LLVMObjectEmitterVisitor::on_unit_end(TranslationUnit& unit) -> void {
    (void)unit;
  }
  
  auto LLVMObjectEmitterVisitor::BYTE() -> llvm::Type* {
    return dynamic_cast<Type*>(Namespace::get_global_namespace()->find_struct("byte"))->to_llvm_type();
  }

  auto LLVMObjectEmitterVisitor::INT() -> llvm::Type* {
    return dynamic_cast<Type*>(Namespace::get_global_namespace()->find_struct("int"))->to_llvm_type();
  }

  auto LLVMObjectEmitterVisitor::BOOL() -> llvm::Type* {
    return dynamic_cast<Type*>(Namespace::get_global_namespace()->find_struct("bool"))->to_llvm_type();
  }

  auto LLVMObjectEmitterVisitor::VOID() -> llvm::Type* {
    return dynamic_cast<Type*>(Namespace::get_global_namespace()->find_struct("void"))->to_llvm_type();
  }

  auto LLVMObjectEmitterVisitor::VOIDPTR() -> llvm::Type* {
    auto Void = dynamic_cast<Type*>(Namespace::get_global_namespace()->find_struct("void"));
    return PointerType::get(*Void, 1)->to_llvm_type();
  }

  auto LLVMObjectEmitterVisitor::FLOAT() -> llvm::Type* {
    return dynamic_cast<Type*>(Namespace::get_global_namespace()->find_struct("float"))->to_llvm_type();
  }

  auto LLVMObjectEmitterVisitor::PRINTF() -> llvm::Function* {
    static llvm::Function* S_printf = llvm::Function::Create(
      llvm::FunctionType::get(
        llvm::Type::getInt32Ty(LLVMWrapper::instance().context()),
        llvm::PointerType::get(LLVMWrapper::instance().context(), 0),
        true
      ),
      llvm::GlobalValue::LinkageTypes::ExternalLinkage,
      "printf",
      LLVMWrapper::instance().module()
    );

    return S_printf;
  }
}
