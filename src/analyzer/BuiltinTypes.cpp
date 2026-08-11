#include <fridayc.hpp>


namespace friday::inline api {
  auto ErrorType::get_name() const noexcept -> string_view {
    return this->M_name;
  }

  auto ErrorType::to_llvm_type() const noexcept -> llvm::Type* {
    return nullptr;
  }
  
  auto ErrorType::get() -> Type* {
    static ErrorType ERROR;
    return dynamic_cast<Type*>(&ERROR);
  }

  auto ErrorType::is_error_type(Type* type) -> bool {
    return type == ErrorType::get();
  }
  
  auto UnresolvedOverloadType::get_name() const noexcept -> string_view {
    return this->M_name;
  }

  auto UnresolvedOverloadType::to_llvm_type() const noexcept -> llvm::Type* {
    return nullptr;
  }
  
  auto UnresolvedOverloadType::get() -> Type* {
    static UnresolvedOverloadType UNRESOLVED_OVERLOAD;
    return dynamic_cast<Type*>(&UNRESOLVED_OVERLOAD);
  }

  auto NamespaceType::get_name() const noexcept -> string_view {
    return this->M_name;
  }

  auto NamespaceType::to_llvm_type() const noexcept -> llvm::Type* {
    return nullptr;
  }
  
  auto NamespaceType::get() -> Type* {
    static NamespaceType NAMESPACE_TYPE;
    return dynamic_cast<Type*>(&NAMESPACE_TYPE);
  }

  auto TypeType::get_name() const noexcept -> string_view {
    return this->M_name;
  }

  auto TypeType::to_llvm_type() const noexcept -> llvm::Type* {
    return nullptr;
  }
  
  auto TypeType::get() -> Type* {
    static TypeType TYPE_TYPE;
    return dynamic_cast<Type*>(&TYPE_TYPE);
  }

  PointerType::PointerType(Type& pointedType, u64 dimensions) noexcept {
    this->M_pointedType = &pointedType;
    this->M_dimensions = dimensions;
    this->M_name = format("{:*>{}}{}", "", this->M_dimensions, this->M_pointedType->get_name());
  }

  auto PointerType::get_name() const noexcept -> string_view {
    return this->M_name;
  }

  auto PointerType::to_llvm_type() const noexcept -> llvm::Type* {
    return LLVMWrapper::get_pointer_type(this->M_pointedType->to_llvm_type());
  }

  auto PointerType::get_pointed_type() const noexcept -> Type* {
    return this->M_pointedType;
  }

  auto PointerType::get_dimensions() const noexcept -> u64 {
    return this->M_dimensions;
  }

  auto PointerType::get(Type& elementType, u64 dimensions) noexcept -> Type* {
    static map<string, unique_ptr<PointerType>> S_pointerTypes = {};

    if(dimensions > 1) return PointerType::get(*PointerType::get(elementType, dimensions-1), 1);
    
    string name = format("{:*>{}}{}", "", dimensions, elementType.get_name());

    if(S_pointerTypes.contains(name)) {
      return dynamic_cast<Type*>(S_pointerTypes.at(name).get());
    } else return dynamic_cast<Type*>(
      S_pointerTypes
      .emplace(name, unique_ptr<PointerType>(new PointerType(elementType, dimensions)))
      .first
      ->second
      .get()
    );
  }
  
  auto PointerType::to_pointer(Type* type) -> PointerType* {
    return dynamic_cast<PointerType*>(type);
  }

  auto PointerType::is_pointer(Type* type) -> bool {
    return dynamic_cast<PointerType*>(type) != nullptr;
  }

  FunctionType::FunctionType(Type& returnType, vector<Type*> paramsTypes) noexcept
    : Type { }
  {
    this->M_returnType = &returnType;
    this->M_parameters = paramsTypes;
    this->M_name = format(
      "{}({})",
      this->M_returnType->get_name(), 
      this->M_parameters
      | views::transform(&Type::get_name)
      | views::join_with(", "s)
      | ranges::to<string>()
    );
  }

  auto FunctionType::get_params_types() const noexcept -> vector<Type*> const& {
    return this->M_parameters;
  }

  auto FunctionType::get_name() const noexcept -> string_view {
    return this->M_name;
  }
  
  auto FunctionType::params_size() const noexcept -> u64 {
    return this->M_parameters.size();
  }

  auto FunctionType::to_llvm_type() const noexcept -> llvm::Type* {
    auto args = this->M_parameters
    | views::transform(&Type::to_llvm_type)
    | ranges::to<vector>();  
    
    return LLVMWrapper::get_function_type(
      this->M_returnType->to_llvm_type(),
      span{ args.data(), args.size() }
    );
  }

  auto FunctionType::get(Type& returnType, vector<Type*> paramsTypes) noexcept -> Type* {
    static map<string, unique_ptr<FunctionType>> S_functionTypes = {};

    string name = format(
      "{}({})",
      returnType.get_name(), 
      paramsTypes
      | views::transform(&Type::get_name)
      | views::join_with(", "s)
      | ranges::to<string>()
    );

    if(S_functionTypes.contains(name)) {
      return dynamic_cast<Type*>(S_functionTypes.at(name).get());
    } else return dynamic_cast<Type*>(
      S_functionTypes
      .emplace(name, unique_ptr<FunctionType>(new FunctionType(returnType, paramsTypes)))
      .first
      ->second
      .get()
    );
  }

  auto FunctionType::get_param_type(u64 index) const -> Type* {
    return this->M_parameters.at(index);
  }

  auto FunctionType::get_return_type() const noexcept -> Type* {
    return this->M_returnType;
  }

  auto FunctionType::param_begin() const -> vector<Type*>::const_iterator {
    return this->M_parameters.begin();
  }

  auto FunctionType::param_end() const -> vector<Type*>::const_iterator {
    return this->M_parameters.end();
  }

  auto FunctionType::to_function(Type* type) -> FunctionType* {
    return dynamic_cast<FunctionType*>(type);
  }

  auto FunctionType::is_function(Type* type) -> bool {
    return dynamic_cast<FunctionType*>(type) != nullptr;
  }

  PrimitiveType::PrimitiveType(string name, llvm::Type* T)
    : Struct { *Namespace::get_global_namespace(), name }
    , M_type { T }
  {}

  auto PrimitiveType::Factory::create(string name, llvm::Type* T) -> PrimitiveType* {
    static vector<unique_ptr<PrimitiveType>> S_instances { };
    S_instances.push_back(unique_ptr<PrimitiveType>(new PrimitiveType(name, T)));
    return S_instances.back().get();
  }

  auto PrimitiveType::to_llvm_type() const noexcept -> llvm::Type* {
    return this->M_type;
  }

  ArrayType::ArrayType(Type& elementType) noexcept 
    : Struct{ *Namespace::get_global_namespace(), format("[]{}", elementType.get_name()) }
  {
    auto intType = dynamic_cast<Type*>(Namespace::get_global_namespace()->find_struct("int"));
    auto ptrType = PointerType::get(elementType, 1);
    auto ptrField = Variable::Factory::create(*this, "ptr", *ptrType);
    auto lenField = Variable::Factory::create(*this, "len", *intType);

    this->define(ptrField);
    this->define(lenField);
  }

  auto ArrayType::get(Type& elementType) noexcept -> Type* {
    static map<string, unique_ptr<ArrayType>> S_arrayTypes = {};

    string name = format("[]{}", elementType.get_name());

    if(S_arrayTypes.contains(name)) {
      return dynamic_cast<Type*>(S_arrayTypes.at(name).get());
    } else return dynamic_cast<Type*>(
      S_arrayTypes
      .emplace(name, unique_ptr<ArrayType>(new ArrayType(elementType)))
      .first
      ->second
      .get()
    );
  }

  auto ArrayType::get_element_type() const noexcept -> Type* {
    return PointerType::to_pointer(this->find_field("ptr")->get_type())->get_pointed_type();
  }

  auto ArrayType::to_array(Type* type) -> ArrayType* {
    return dynamic_cast<ArrayType*>(type);
  }

  auto ArrayType::is_array(Type* type) -> bool {
    return dynamic_cast<ArrayType*>(type) != nullptr;
  }

  
}