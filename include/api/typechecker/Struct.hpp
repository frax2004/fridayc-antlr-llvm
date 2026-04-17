#pragma once

#include "Type.hpp"
#include "Variable.hpp"
#include "Function.hpp"

namespace friday::inline api::inline typechecker {
  
  /// @brief Represents a type in the type system
  struct Struct : public Symbol, public Type {
    private:
    /// @brief The struct name
    String M_name;
    /// @brief the struct fields
    Map<String, Variable> M_fields;
    /// @brief the struct methods
    Map<String, Function> M_methods;
    /// @brief The struct visibility modifier
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

    /// @brief Adds a method the struct
    /// @param method the method
    /// @return `true` if the method was added. The method is added if there was no method with the same name defined before
    auto addMethod(Function method) noexcept -> bool; 

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

    /// @brief Get the visibility modifier of the struct
    /// @return the visibility modifier
    auto getVisibility() const noexcept -> VisibilityModifier override;

    /// @brief Get the type
    /// @return the type
    auto getType() const noexcept -> Type* override;

    /// @brief Get the name of the struct
    /// @return the name of the struct
    auto getName() const noexcept -> String const& override;

    /// @brief Gets the internal llvm type of the struct
    /// @return the llvm type
    virtual auto getLLVMType(llvm::LLVMContext& ctx) const noexcept -> llvm::Type* override;
    
    /// @brief Gets the standard primitive int type
    /// @param ctx the llvm context
    /// @return the int type
    static auto getIntType(llvm::LLVMContext& ctx) -> Type*;
    
    /// @brief Gets the standard primitive float type
    /// @param ctx the llvm context
    /// @return the float type
    static auto getFloatType(llvm::LLVMContext& ctx) -> Type*;
    
    /// @brief Gets the standard primitive byte type
    /// @param ctx the llvm context
    /// @return the byte type
    static auto getByteType(llvm::LLVMContext& ctx) -> Type*;
    
    /// @brief Gets the standard primitive bool type
    /// @param ctx the llvm context
    /// @return the bool type
    static auto getBoolType(llvm::LLVMContext& ctx) -> Type*;
    
    /// @brief Gets the standard primitive void type
    /// @param ctx the llvm context
    /// @return the void type
    static auto getVoidType(llvm::LLVMContext& ctx) -> Type*;
    
    /// @brief Get the default error type
    /// @return the error type instance
    static auto getErrorType() -> Type*;
}; // struct Struct
} // namespace friday::api::typechecker

