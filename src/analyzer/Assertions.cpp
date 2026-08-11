#include <fridayc.hpp>


namespace traits {
  template<class Factory, class Product>
  concept factory = requires(Factory factory) {
    &Factory::create;
    requires(is_function_v<decltype(Factory::create)>);
  };
  
  template<class Type>
  concept supports_factory_method = requires(Type x) {
    typename Type::Factory;
    requires(factory<typename Type::Factory, Type>);
  };
}


namespace friday {
  static_assert(traits::supports_factory_method<Variable>, "Variable must support factory method");
  static_assert(traits::supports_factory_method<Struct>, "Struct must support factory method");
  static_assert(traits::supports_factory_method<ArrayType>, "ArrayType must support factory method");
  static_assert(traits::supports_factory_method<Function>, "Function must support factory method");
  static_assert(traits::supports_factory_method<Overload>, "Overload must support factory method");
  static_assert(traits::supports_factory_method<Namespace>, "Namespace must support factory method");
  static_assert(traits::supports_factory_method<Scope>, "Scope must support factory method");
  static_assert(traits::supports_factory_method<PrimitiveType>, "PrimitiveType must support factory method");
}