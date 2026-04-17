#pragma once


#include "Symbol.hpp"


namespace friday::inline api::inline typechecker {
  
  /// @brief Represents a type in the type system
  struct Type {
    private:
    /// @brief the struct visibility modifier
    VisibilityModifier M_visibility;

    public:
    /// @brief Tells if this type is an instance of one of the subtypes allowed
    /// @tparam T a subtype
    /// @return true if `this` instance is a runtime instance of `T`
    template<std::derived_from<Type> T>
    auto is() const noexcept -> bool;

    /// @brief Attempts to cast `this` instance into subtype `T`
    /// @tparam T a subtype
    /// @return `this` instance cast as `T` or nullptr othewise
    template<std::derived_from<Type> T>
    auto as() noexcept -> T*;

    /// @brief Constructs a struct
    /// @param name the name
    /// @param visibility the visibility modifier
    Type(VisibilityModifier visibility = VisibilityModifier::PUBLIC) noexcept;

    /// @brief Get the internal llvm type
    /// @return pointer to the type
    virtual auto getLLVMType(llvm::LLVMContext& ctx) const noexcept -> llvm::Type* = 0;

    /// @brief Gets the name of the struct
    /// @return the name of the struct
    virtual auto getName() const noexcept -> String const& = 0;
    
    /// @brief Gets the visibility modifier of the type
    /// @return the visibility modifier
    virtual auto getVisibility() const noexcept -> VisibilityModifier;

  }; // struct Type
} // namespace friday::api::typechecker

#include "Type.inl"