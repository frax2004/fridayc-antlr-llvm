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

    /// @brief Gets the unary operator name for the given type
    /// @param oper the unary operator
    /// @param T the type
    /// @return the name of the unary operator
    static auto getUnaryOperatorName(u64 oper, Type* T) noexcept -> String; 

    /// @brief Gets the binary operator name for the given types
    /// @param oper the binary operator
    /// @param T the lhs type
    /// @param U the rhs type
    /// @return the name of the binary operator
    static auto getBinaryOperatorName(u64 oper, Type* T, Type* U) noexcept -> String; 

  }; // struct Type
} // namespace friday::api::typechecker

#include "Type.inl"