#pragma once

#include "Symbol.hpp"
#include "Variable.hpp"
#include "Function.hpp"

namespace friday::inline api::inline typechecker {

  struct Variable;
  struct Function;
  
  struct Struct : public Symbol {
    private:
    String name;
    llvm::Type* type;
    Map<String, Variable> fields;
    Map<String, Function> methods;
    VisibilityModifier visibility;

    public:
    Struct(
      String name, 
      Map<String, Variable> fields = {}, 
      Map<String, Function> methods = {},
      VisibilityModifier visibility = VisibilityModifier::PUBLIC
    ) noexcept;

    auto setName(String name) noexcept -> Struct&;
    auto addField(Variable field) -> Struct&;
    auto addMethod(Function method) -> Struct&;
    auto setVisibility(VisibilityModifier visibility) -> Struct&;

    auto getName() const noexcept -> String const&;
    auto getField(String const& name) const noexcept -> Variable const&;
    auto getMethod(String const& name) const noexcept -> Function const&;
    
    auto getVisibility() const noexcept -> VisibilityModifier override;
    auto getLLVMType() const noexcept -> llvm::Type* override;
    
    static auto getErrorType() -> Struct*;
  };

}

