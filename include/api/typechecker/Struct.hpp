#pragma once

#include "Symbol.hpp"
#include "Variable.hpp"
#include "Function.hpp"

namespace friday::inline api::inline typechecker {

  struct Variable;
  struct Function;

  /// @brief Represents a type in the type system
  struct Struct : public Symbol {
    private:
    /// @brief the struct name
    String M_name;
    /// @brief the struct internal type
    llvm::Type* M_type;
    /// @brief the struct fields
    Map<String, Variable> M_fields;
    /// @brief the struct methods
    Map<String, Function> M_methods;
    /// @brief the struct visibility modifier
    VisibilityModifier M_visibility;

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

    /// @brief Sets the name of the struct
    /// @param name the name
    /// @return reference to `*this` instance
    auto setName(String name) noexcept -> Struct&;
    
    /// @brief Adds a field to the struct 
    /// @param field the field
    /// @return reference to `*this` instance
    auto addField(Variable field) -> Struct&;

    /// @brief Adds a method to the struct
    /// @param method the method
    /// @return reference to `*this` instance
    auto addMethod(Function method) -> Struct&;

    /// @brief Sets the visibility modifier to the struct
    /// @param visibility the visibility modifier
    /// @return reference to `*this` instance
    auto setVisibility(VisibilityModifier visibility) -> Struct&;

    /// @brief Gets the name of the struct
    /// @return the name of the struct
    auto getName() const noexcept -> String const&;
    
    /// @brief Gets the field of the struct with the given name 
    /// @param name the name of the field
    /// @return the field
    auto getField(String const& name) const noexcept -> Variable*;

    /// @brief Gets the method of the struct with the given name
    /// @param name the name of the method
    /// @return the method
    auto getMethod(String const& name) const noexcept -> Function*;

    /// @brief Gets the visibility modifier of the struct
    /// @return the visibility modifier
    auto getVisibility() const noexcept -> VisibilityModifier override;

    /// @brief Gets the internal llvm type of the struct
    /// @return the llvm type
    auto getLLVMType() const noexcept -> llvm::Type* override;

    /// @brief Get the default error type
    /// @return the error type instance
    static auto getErrorType() -> Struct*;
  }; // struct Struct
} // namespace friday::api::typechecker

