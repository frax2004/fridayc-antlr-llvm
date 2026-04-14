#pragma once

#include "Symbol.hpp"
#include "Variable.hpp"

namespace friday::inline api::inline typechecker {

  struct Function : public Symbol {
    private:
    String name;
    llvm::Type* type;
    Map<String, Variable> parameters;
    VisibilityModifier visibility;

    public:
    Function(
      String name,
      Map<String, Variable> parameters = {},
      VisibilityModifier visibility = VisibilityModifier::PUBLIC
    );

    auto setName(String name) noexcept -> Function&;
    auto setVisibiltiy(VisibilityModifier visibility) noexcept -> Function&;
    auto addParameter(Variable parameter) noexcept -> Function&;

    auto getParameter(String const& name) const noexcept -> Variable*;
    auto getVisibility() const noexcept -> VisibilityModifier override;
    auto getLLVMType() const noexcept -> llvm::Type* override;
  };


}

