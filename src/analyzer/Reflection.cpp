#include <fridayc.hpp>


namespace friday::inline api {

  auto Reflection::reflect_namespace(Namespace* nsp) -> llvm::Value* {
    return llvm::ConstantStruct::getAnon({
      Constant::from_str(nsp->get_qualified_id()).to_llvm_constant()
    });
  }

  auto Reflection::reflect_type(Type* type) -> llvm::Value* {
    return llvm::ConstantStruct::getAnon({
      Constant::from_str(string{ type->get_name() }).to_llvm_constant(),
      Constant::from_int(type->size()).to_llvm_constant(),
      Constant::from_int(type->alignment()).to_llvm_constant()
    });
  }

}