#pragma once

//* ////////////////////////////////////////////////////////////////

//* ///////////////////////////
#include <Struct.hpp>
//* ///////////////////////////

//* ////////////////////////////////////////////////////////////////

namespace friday::inline api::inline typesystem {

  /**
   * @brief Represents type for arrays, that is, a struct with a pointer and a length
   */
  struct FRIDAY_API ArrayType final : Struct {

  private:
    /**
     * @brief Constructs an array type instance
     * @param global the global namespace
     * @param elementType the element type
     * @param name the name of the array type
     */
    ArrayType(Namespace& global, Type& elementType, string name) noexcept;

  public:
    /**
     * @brief Default destructor
     */
    ~ArrayType() override = default;

  public:
    /**
     * @brief Get an array type
     * @param global the global namespace
     * @param elementType the element type
     * @return reference to the instance of the array type
     */
    static auto get(Namespace& global, Type& elementType) noexcept -> Type*;

  public:
    /**
     * @brief Get the element type
     * @return the element type
     */
    auto get_element_type() const noexcept -> Type*;

  public:
    /**
     * @brief Convert a type instance to an array type instance through `dynamic_cast`
     * @param type the object
     * @return array type instance or `nullptr` if the runtime type was `not ArrayType`
     */
    static auto to_array(Type* type) -> ArrayType*;

  public:
    /**
     * @brief Check if a type is an instance of ArrayType at runtime through `dynamic_cast`
     * @param type the object
     * @return `true` if the runtime type of the object is `ArrayType`
     */
    static auto is_array(Type* type) -> bool;
  };

  //* ///////////////////////////////////////////////////////////////////////
  //* ///////////////////////////////////////////////////////////////////////
  //* ///////////////////////////////////////////////////////////////////////

  /**
   * @brief Represents an illegal compile time type
   */
  struct FRIDAY_API ErrorType final : Type {

  private:
    /**
     * @brief The name of the type
     */
    string M_name { "<error-type>" };

  private:
    /**
     * @brief Default constructor
     */
    constexpr ErrorType() = default;

  public:
    /**
     * @brief Default destructor
     */
    constexpr ~ErrorType() override = default;

  public:
    /**
     * @brief Get the name of the type
     * @return the name of the type
     */
    auto get_name() const noexcept -> string_view override;

  public:
    /**
     * @brief Convert the type to its llvm type representation
     * @param ctx llvm context
     * @return reference to the llvm type
     */
    auto to_llvm_type(llvm::LLVMContext& ctx) const noexcept -> Pointer<llvm::Type> override;
  
  public:
    /**
     * @brief Get the error type instance
     * @return the error type reference
     */
    static auto get() -> Type*;
  
  public:
    /**
     * @brief Check if a type is the error type
     * @param type the type
     * @return `true` if the type is the error type
     */
    static auto is_error_type(Type* type) -> bool;
  };

  //* ///////////////////////////////////////////////////////////////////////
  //* ///////////////////////////////////////////////////////////////////////
  //* ///////////////////////////////////////////////////////////////////////

  struct FRIDAY_API FunctionType final : Type {
  private:
    /**
     * @brief The parameters types
     */
    vector<Type*> M_parameters { };

  private:
    /**
     * @brief the type name
     */
    string M_name { "" };

  private:
    /**
     * @brief the return type
     */
    Type* M_returnType { nullptr };

  private:
    /**
     * @brief Construct a function type
     * @param returnType the return type
     * @param paramsTypes the parameters types
     */
    FunctionType(Type& returnType, vector<Type*> paramsTypes) noexcept;

  public:
    /**
     * @brief Default destructor
     */
    ~FunctionType() override = default;

  public:
    /**
     * @brief Get a function type
     * @param returnType the return type
     * @param paramsTypes the parameters types
     * @return reference to the function type
     */
    static auto get(Type& returnType, vector<Type*> paramsTypes) noexcept -> Type*;
  
  public:
    /**
     * @brief Checks if a type is a function type through `dynamic_cast`
     * @param type the object
     * @return `true` if the runtime type is a `FunctionType`
     */
    static auto is_function(Type* type) -> bool;
  
  public:
    /**
     * @brief Convert a type instance to a function type instance through `dynamic_cast`
     * @param type the object
     * @return function type instance or `nullptr` if the runtime type was `not FunctionType`
     */
    static auto to_function(Type* type) -> FunctionType*;

  public:
    /**
     * @brief Get the begin iterator for the parameters types
     * @return begin iterator to the parameters types
     */
    auto param_begin() const -> vector<Type*>::const_iterator;
  
  public:
    /**
     * @brief Get the end iterator for the parameters types
     * @return end iterator to the parameters types
     */
    auto param_end() const -> vector<Type*>::const_iterator;

  public:
    /**
     * @brief Get a parameter type
     * @param index index of the parameter
     * @return reference to the parameter type
     */
    auto get_param_type(u64 index) const -> Type*;

  public:
    /**
     * @brief Get the parameters types
     * @return the parameters types
     */
    auto get_params_types() const noexcept -> vector<Type*> const&;

  public:
    /**
     * @brief Get the parameters count
     * @return the number of parameters
     */
    auto params_size() const noexcept -> u64;

  public:
    /**
     * @brief Get the return type
     * @return the return type
     */
    auto get_return_type() const noexcept -> Type*;

  public:
    /**
     * @brief Convert the type to its llvm type representation
     * @param ctx llvm context
     * @return reference to the llvm type
     */
    auto to_llvm_type(llvm::LLVMContext& ctx) const noexcept -> Pointer<llvm::Type> override;

  public:
    /**
     * @brief Get the name of the type
     * @return the name of the type
     */
    auto get_name() const noexcept -> string_view override;

  };

  //* ///////////////////////////////////////////////////////////////////////
  //* ///////////////////////////////////////////////////////////////////////
  //* ///////////////////////////////////////////////////////////////////////

  /**
   * @brief Represents the type of namespaces
   */
  struct FRIDAY_API NamespaceType final : Type {
  private:
    /**
     * @brief The name of the type
     */
    string M_name { "<type-of-namespaces>" };

  private:
    /**
     * @brief Default constructor
     */
    constexpr NamespaceType() = default;

  public:
    /**
     * @brief Default destructor
     */
    constexpr ~NamespaceType() override = default;

  public:
    /**
     * @brief Get the name of the type
     * @return the name of the type
     */
    auto get_name() const noexcept -> string_view override;

  public:
    /**
     * @brief Convert the type to its llvm type representation
     * @param ctx llvm context
     * @return reference to the llvm type
     */
    auto to_llvm_type(llvm::LLVMContext& ctx) const noexcept -> Pointer<llvm::Type> override;
    
  public:
    /**
     * @brief Get the namespace type instance
     * @return the namespace type reference
     */
    static auto get() -> Type*;

  };

  //* ///////////////////////////////////////////////////////////////////////
  //* ///////////////////////////////////////////////////////////////////////
  //* ///////////////////////////////////////////////////////////////////////

  /**
   * @brief Represents type for arrays, that is, a struct with a pointer and a length
   */
  struct FRIDAY_API PointerType final : Type {
  
  private:
    /**
     * @brief The name of the type
     */
    string M_name { "" };

  private:
    /**
     * @brief The pointed type
     */
    Type* M_pointedType { nullptr };

  private:
    /**
     * @brief The dimensions of the pointer
     */
    u64 M_dimensions { 0 };

  private:
    /**
     * @brief Construct a pointer type
     * @param pointedType the pointed type
     * @param dimensions the dimensions
     * @param name the name of the type
     */
    PointerType(Type& pointedType, u64 dimensions, string name) noexcept;

  public:
    /**
     * @brief Default destructor
     */
    ~PointerType() override = default;

  public:
    /**
     * @brief Get the pointer type
     * @param pointedType pointed type
     * @param dimensions dimensions of the pointer type
     * @return reference to the instance of the pointer type
     */
    static auto get(Type& pointedType, u64 dimensions) noexcept -> Type*;

  public:
    /**
     * @brief Get the pointed type
     * @return the pointed type
     */
    auto get_pointed_type() const noexcept -> Type*;

  public:
    /**
     * @brief Get the dimensions of the pointer
     * @return the dimensions
     */
    auto get_dimensions() const noexcept -> u64;

  public:
    /**
     * @brief Get the name of the type
     * @return the name of the type
     */
    auto get_name() const noexcept -> string_view override;

  public:
    /**
     * @brief Convert the type to its llvm type representation
     * @param ctx llvm context
     * @return reference to the llvm type
     */
    auto to_llvm_type(llvm::LLVMContext& ctx) const noexcept -> Pointer<llvm::Type> override;

  public:
    /**
     * @brief Convert a type instance to a pointer type instance through `dynamic_cast`
     * @param type the object
     * @return pointer type instance or `nullptr` if the runtime type was `not PointerType`
     */
    static auto to_pointer(Type* type) -> PointerType*;

  public:
    /**
     * @brief Checks if a type is a pointer type through `dynamic_cast`
     * @param type the object
     * @return `true` if the runtime type is a `PointerType`
     */
    static auto is_pointer(Type* type) -> bool;
  };

  //* ///////////////////////////////////////////////////////////////////////
  //* ///////////////////////////////////////////////////////////////////////
  //* ///////////////////////////////////////////////////////////////////////

  /**
   * @brief Represents a primitive type (int, float, ...)
   */
  struct FRIDAY_API PrimitiveType final : Struct {
  
  private:
    /**
     * @brief The name of the type
     */
    string M_name { "" };
  
  private:
    /**
     * @brief The internal llvm type
     */
    Pointer<llvm::Type> M_type { nullptr };

  private:
    /**
     * @brief Construct a primitive type
     * @param global the global namespace
     * @param name the name
     * @param T internal llvm type
     */
    PrimitiveType(Namespace& global, string name, Pointer<llvm::Type> T);

  public:
    /**
     * @brief Default destructor
     */
    ~PrimitiveType() override = default;

  public:
    /**
     * @brief Convert the type to its llvm type representation
     * @param ctx llvm context
     * @return reference to the llvm type
     */
    auto to_llvm_type(llvm::LLVMContext& ctx) const noexcept -> Pointer<llvm::Type> override;
  };

  //* ///////////////////////////////////////////////////////////////////////
  //* ///////////////////////////////////////////////////////////////////////
  //* ///////////////////////////////////////////////////////////////////////

  /**
   * @brief Represents the type of function overloads
   */
  struct FRIDAY_API UnresolvedOverloadType final : Type {
  private:
    /**
     * @brief the name of the type
     */
    string M_name { "<unresolved-overload-type>" };

  private:
    /**
     * @brief Default constructor
     */
    constexpr UnresolvedOverloadType() = default;

  public:
    /**
     * @brief Default destructor
     */
    constexpr ~UnresolvedOverloadType() override = default;

  public:
    /**
     * @brief Get the type name
     * @return the type name
     */
    auto get_name() const noexcept -> string_view override;

  public:
    /**
     * @brief Convert the type to its llvm type representation
     * @param ctx llvm context
     * @return reference to the llvm type
     */
    auto to_llvm_type(llvm::LLVMContext& ctx) const noexcept -> Pointer<llvm::Type> override;
    
  public:
    /**
     * @brief Get the reference to the instance of the type of function overloads
     * @return reference to the instance of the type of function overloads
     */
    static auto get() -> Type*;

  };

  //* ///////////////////////////////////////////////////////////////////////
  //* ///////////////////////////////////////////////////////////////////////
  //* ///////////////////////////////////////////////////////////////////////

  struct FRIDAY_API TypeType final : Type {
  private:
    /**
     * @brief The name of the type
     */
    string M_name { "<type-of-types>" };

  private:
    /**
     * @brief Default constructor
     */
    constexpr TypeType() = default;

  public:
    /**
     * @brief Default destructor
     */
    constexpr ~TypeType() override = default;

  public:
    /**
     * @brief Get the type name
     * @return the type name
     */
    auto get_name() const noexcept -> string_view override;

  public:
    /**
     * @brief Convert the type to its llvm type representation
     * @param ctx llvm context
     * @return reference to the llvm type
     */
    auto to_llvm_type(llvm::LLVMContext& ctx) const noexcept -> Pointer<llvm::Type> override;

  public:
    /**
     * @brief Get the reference to the instance of the type of types
     * @return reference to the instance of the type of types
     */
    static auto get() -> Type*;

  };
}

