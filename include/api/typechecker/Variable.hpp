#pragma once

#include "Symbol.hpp"

namespace friday::inline api::inline typechecker {

  struct Struct;

  struct Variable : public Symbol {
    private:
    String name;
    Struct* type;
    VisibilityModifier visiblity;
    
    public:
    auto getLLVMType() const noexcept -> llvm::Type* override;
    auto getVisibility() const noexcept -> VisibilityModifier override;
  };
}