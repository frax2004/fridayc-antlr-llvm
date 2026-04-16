#pragma once

#include "Type.hpp"
#include "Variable.hpp"
#include "Function.hpp"
#include "StructType.hpp"

namespace friday::inline api::inline typechecker {
  
  /// @brief Represents a type in the type system
  struct Struct : public Symbol {
    private:
    /// @brief the struct fields
    Map<String, Variable> M_fields;
    /// @brief the struct methods
    Map<String, Function> M_methods;
    /// @brief The struct signature
    StructType* M_signature;

    public:
    /// @brief Constructs a struct
    /// @param name the name
    /// @param fields the fields
    /// @param methods the methods
    /// @param visibility the visibility modifier
    Struct(
      String name, 
      Map<String, Variable> fields = {}, 
      Map<String, Function> methods = {},
      VisibilityModifier visibility = VisibilityModifier::PUBLIC
    ) noexcept;

    /// @brief Gets the field of the struct with the given name 
    /// @param name the name of the field
    /// @param defaultValue a fallback value
    /// @return the field or defaultValue if not present
    auto getField(String const& name, const Variable* defaultValue = nullptr) const noexcept -> const Variable*;

    /// @brief Gets the method of the struct with the given name
    /// @param name the name of the method
    /// @param defaultValue a fallback value 
    /// @return the method or defaultValue if not present
    auto getMethod(String const& name, const Function* defaultValue = nullptr) const noexcept -> const Function*;

    /// @brief Get the type
    /// @return the type
    auto getType() const noexcept -> Type* override;

    /// @brief Gets the internal llvm type of the struct
    /// @return the llvm type
    auto getLLVMType(llvm::LLVMContext& ctx) const noexcept -> llvm::Type* override;
  }; // struct Struct
} // namespace friday::api::typechecker

