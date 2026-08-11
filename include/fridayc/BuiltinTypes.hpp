#pragma once
#include "Struct.hpp"


namespace friday::inline api {

  struct ErrorType final : Type {
  private:
    string M_name { "<error-type>" };

    constexpr ErrorType() = default;

  public:
    constexpr ~ErrorType() override = default;

    auto get_name() const noexcept -> string_view override;
    auto to_llvm_type() const noexcept -> llvm::Type* override;

    static auto get() -> Type*;
    static auto is_error_type(Type* type) -> bool;
  };

  struct NamespaceType final : Type {
  private:
    string M_name { "<type-of-namespaces>" };

    constexpr NamespaceType() = default;
    
  public:
    constexpr ~NamespaceType() override = default;

    auto get_name() const noexcept -> string_view override;
    auto to_llvm_type() const noexcept -> llvm::Type* override;
    static auto get() -> Type*;

  };


  struct UnresolvedOverloadType final : Type {
  private:
    string M_name { "<unresolved-overload-type>" };

  private:
    constexpr UnresolvedOverloadType() = default;

  public:
    constexpr ~UnresolvedOverloadType() override = default;

    auto get_name() const noexcept -> string_view override;
    auto to_llvm_type() const noexcept -> llvm::Type* override;
    static auto get() -> Type*;

  };

  struct TypeType final : Type {
  private:
    string M_name { "<type-of-types>" };

  private:
    constexpr TypeType() = default;

  public:
    constexpr ~TypeType() override = default;

    auto get_name() const noexcept -> string_view override;
    auto to_llvm_type() const noexcept -> llvm::Type* override;
    static auto get() -> Type*;

  };


  struct PointerType final : Type {
  
  private:
    Type* M_pointedType { nullptr };
    u64 M_dimensions { 0 };
    string M_name { "" };

  private:
    PointerType(Type& pointedType, u64 dimensions) noexcept;

  public:
    ~PointerType() override = default;

    static auto get(Type& pointedType, u64 dimensions) noexcept -> Type*;

    auto get_pointed_type() const noexcept -> Type*;
    auto get_dimensions() const noexcept -> u64;
    auto get_name() const noexcept -> string_view override;
    auto to_llvm_type() const noexcept -> llvm::Type* override;
    
    static auto to_pointer(Type* type) -> PointerType*;
    static auto is_pointer(Type* type) -> bool;
  };

  struct FunctionType final : Type {
  private:
    vector<Type*> M_parameters { };
    Type* M_returnType { nullptr };
    string M_name { "" };

    FunctionType(Type& returnType, vector<Type*> paramsTypes) noexcept;

  public:
    ~FunctionType() override = default;

    static auto get(Type& returnType, vector<Type*> paramsTypes) noexcept -> Type*;
    static auto is_function(Type* type) -> bool;
    static auto to_function(Type* type) -> FunctionType*;

    auto param_begin() const -> vector<Type*>::const_iterator;
    auto param_end() const -> vector<Type*>::const_iterator;
    auto get_param_type(u64 index) const -> Type*;
    auto get_params_types() const noexcept -> vector<Type*> const&;
    auto params_size() const noexcept -> u64;
    auto get_return_type() const noexcept -> Type*;
    auto to_llvm_type() const noexcept -> llvm::Type* override;
    auto get_name() const noexcept -> string_view override;

  };

  struct PrimitiveType final : Struct {
  public:
    struct Factory {
      static auto create(string name, llvm::Type* T) -> PrimitiveType*;
    };

  private:
    string M_name { "" };
    llvm::Type* M_type { nullptr };

  private:
    PrimitiveType(string name, llvm::Type* T);

  public:
    ~PrimitiveType() override = default;

    auto to_llvm_type() const noexcept -> llvm::Type* override;
  };


  struct ArrayType final : Struct {

  private:
    ArrayType(Type& elementType) noexcept;

  public:
    ~ArrayType() override = default;

    auto get_element_type() const noexcept -> Type*;
    
    static auto get(Type& elementType) noexcept -> Type*;
    static auto to_array(Type* type) -> ArrayType*;
    static auto is_array(Type* type) -> bool;
  };


}

