#include <Type.hpp>

namespace friday::inline api::inline typesystem {

  struct ErrorType : Type {
    auto getName() const noexcept -> String const& override;
    auto getLLVMType(llvm::LLVMContext& ctx) const noexcept -> llvm::Type* override;
    
    private:
    String M_name = "<error-type>"s;
  };

}