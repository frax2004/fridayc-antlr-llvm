#include <ArrayType.hpp>
#include <OperationNotSupportedError.hpp>
#include <PointerType.hpp>
#include <Namespace.hpp>

namespace friday::inline api::inline typesystem {
  ArrayType::ArrayType(Namespace& global, Type& elementType, string name) noexcept 
    : Struct{ global, name }
  {
    auto ptrType = PointerType::get(elementType, 1);
    auto intType = rtti::cast<Type>(global.find_struct("int").lock().get());
    this->define(make_shared<Variable>(*this, "ptr", *ptrType));
    this->define(make_shared<Variable>(*this, "len", *intType));
  }

  auto ArrayType::get(Namespace& global, Type& elementType) noexcept -> Pointer<Type> {
    static map<string, rc<ArrayType>> S_arrayTypes = {};

    string name = "[]{}"_f.format(elementType.get_name());

    if(S_arrayTypes.contains(name)) 
      return rtti::cast<Type>(S_arrayTypes.at(name).get());

    auto ref = new ArrayType{ global, elementType, name };
    auto type = S_arrayTypes[name] = rc<ArrayType>(ref);

    return rtti::cast<Type>(type.get());
  }

  auto ArrayType::get_element_type() const noexcept -> Pointer<Type> {
    return PointerType::to_pointer(this->find_field("ptr").lock()->get_type());
  }

  auto ArrayType::to_array(Pointer<Type> type) -> Pointer<ArrayType> {
    return rtti::cast<ArrayType>(type);
  }

  auto ArrayType::is_array(Pointer<Type> type) -> bool {
    return rtti::instance_of<ArrayType>(type);
  }

  
}