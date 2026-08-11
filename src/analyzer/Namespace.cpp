#include <fridayc.hpp>

namespace friday::inline api {

  using argument = pair<string, Type*>;

  static auto $$(string_view name, Type* type) -> argument {
    return argument{ string{ name }, type };
  }

  template<u64 N>
  using signature = pair<Type*, array<argument, N>>;

  static auto operator&(argument lhs, argument rhs) -> array<argument, 2> {
    return array{ lhs, rhs };
  }

  template<u64 N>
  static auto operator&(array<argument, N> const& lhs, Type& rhs) -> array<argument, N+1> {
    array<argument, N+1> operands {};
    ranges::copy(lhs, operands.begin());
    operands[N] = &rhs;
    return operands;
  }

  template<u64 N>
  static auto operator>>(array<argument, N> const& operands, Type* operand) -> signature<N> {
    return signature{ operand, operands };
  }

  static auto operator>>(argument const& arg, Type* operand) -> signature<1> {
    return signature{ operand, array{arg} };
  }

  template<u64 N>
  static auto operator|(string name, signature<N> func) -> Overload* {
    auto global = dynamic_cast<ISymbolTable*>(Namespace::get_global_namespace());
    auto overload = Overload::Factory::create(*global, name);
    overload->add(
      *func.first, 
      func.second 
      | ranges::to<vector>(),
      Attributes {
        .linkage = Linkage::EXTERNAL 
      }
    );
    return overload;
  }

  template<u64 N>
  static auto operator|(Overload* overload, signature<N> func) -> Overload* {
    overload->add(
      *func.first, 
      func.second 
      | ranges::to<vector>(), 
      Attributes {
        .linkage = Linkage::EXTERNAL 
      }
    );
    return overload;
  }

  Namespace* Namespace::S_globalNamespace = nullptr;
  Namespace::namespace_map_type Namespace::S_namespaces { };

  auto Namespace::Factory::create(string name) -> Namespace* {
    static vector<unique_ptr<Namespace>> S_instances { };

    if(Namespace::S_namespaces.contains(name)) {
      throw InvalidArgumentError{};
    }

    S_instances.push_back(unique_ptr<Namespace>(new Namespace(name)));
    Namespace* instance = S_instances.back().get();
    Namespace::S_namespaces.emplace(name, instance);

    return instance;
  }

  Namespace::Namespace(string name)
    : M_name { name }
  {
    if(Namespace::S_globalNamespace != nullptr and name != "") {
      //*/ 'this' is not the global namespace because its already initialized
      this->M_parentNamespace = Namespace::get_global_namespace();
    }
  }

  auto Namespace::get_type() const -> Type* {
    return NamespaceType::get();
  }

  auto Namespace::find_namespace(string_view name) -> Namespace* {
    auto it = Namespace::S_namespaces.find(name);
    return it != Namespace::S_namespaces.end() ? it->second : nullptr;
  }

  auto Namespace::find_function(string_view id) -> Overload* {
    ISymbol* candidate = this->retrieve_if(id, &Overload::is_overload);
    return candidate != nullptr ? dynamic_cast<Overload*>(candidate) : nullptr;
  }

  auto Namespace::find_struct(string_view id) -> Struct* {
    ISymbol* candidate = this->retrieve_if(id, &Struct::is_struct);
    return candidate != nullptr ? dynamic_cast<Struct*>(candidate) : nullptr;
  }

  auto Namespace::find_variable(string_view id) -> Variable* {
    ISymbol* candidate = this->retrieve_if(id, &Variable::is_variable);
    return candidate != nullptr ? dynamic_cast<Variable*>(candidate) : nullptr;
  }

  auto Namespace::get_qualified_id() const -> string {
    return this->M_name;
  }

  auto Namespace::get_mangled_name_builder() const -> NameMangler {
    return NameMangler { this->get_qualified_id() };
  }

  auto Namespace::get_global_namespace() noexcept -> Namespace* {

    if(Namespace::S_globalNamespace == nullptr) {
      Namespace::S_globalNamespace = Namespace::Factory::create("");

      auto Int = dynamic_cast<Type*>(PrimitiveType::Factory::create("int", LLVMWrapper::get_int_type(64)));
      auto Byte = dynamic_cast<Type*>(PrimitiveType::Factory::create("byte", LLVMWrapper::get_int_type(8)));
      auto Bool = dynamic_cast<Type*>(PrimitiveType::Factory::create("bool", LLVMWrapper::get_int_type(1)));
      auto Float = dynamic_cast<Type*>(PrimitiveType::Factory::create("float", LLVMWrapper::get_double_type()));
      auto Void = dynamic_cast<Type*>(PrimitiveType::Factory::create("void", LLVMWrapper::get_void_type()));
      auto VoidPtr = dynamic_cast<Type*>(PointerType::get(*Void, 1));

      auto plus = "operator+"s
      | ($$("lhs", Int) & $$("rhs", Int)) >> Int
      | ($$("lhs", Float) & $$("rhs", Float)) >> Float
      | ($$("lhs", Byte) & $$("rhs", Byte)) >> Byte
      | ($$("lhs", VoidPtr) & $$("rhs", Int)) >> VoidPtr
      | ($$("value", Int)) >> Int
      | ($$("value", Float)) >> Float
      | ($$("value", Byte)) >> Byte
      ;


      auto minus = "operator-"s
      | ($$("lhs", Int) & $$("rhs", Int)) >> Int
      | ($$("lhs", Float) & $$("rhs", Float)) >> Float
      | ($$("lhs", Byte) & $$("rhs", Byte)) >> Byte
      | ($$("lhs", VoidPtr) & $$("rhs", Int)) >> VoidPtr
      | ($$("lhs", VoidPtr) & $$("rhs", VoidPtr)) >> Int
      | ($$("value", Int)) >> Int
      | ($$("value", Float)) >> Float
      | ($$("value", Byte)) >> Byte
      ;


      auto multiplies = "operator*"s
      | ($$("lhs", Int) & $$("rhs", Int)) >> Int
      | ($$("lhs", Float) & $$("rhs", Float)) >> Float
      | ($$("lhs", Byte) & $$("rhs", Byte)) >> Byte
      ;


      auto divides = "operator/"s
      | ($$("lhs", Int) & $$("rhs", Int)) >> Int
      | ($$("lhs", Float) & $$("rhs", Float)) >> Float
      | ($$("lhs", Byte) & $$("rhs", Byte)) >> Byte
      ;


      auto modulus = "operator%"s
      | ($$("lhs", Int) & $$("rhs", Int)) >> Int
      | ($$("lhs", Float) & $$("rhs", Float)) >> Float
      | ($$("lhs", Byte) & $$("rhs", Byte)) >> Byte
      ;


      auto equal_to = "operator=="s
      | ($$("lhs", Int) & $$("rhs", Int)) >> Bool
      | ($$("lhs", Float) & $$("rhs", Float)) >> Bool
      | ($$("lhs", Byte) & $$("rhs", Byte)) >> Bool
      | ($$("lhs", Bool) & $$("rhs", Bool)) >> Bool
      | ($$("lhs", VoidPtr) & $$("rhs", VoidPtr)) >> Bool
      ;


      auto not_equal_to = "operator!="s
      | ($$("lhs", Int) & $$("rhs", Int)) >> Bool
      | ($$("lhs", Float) & $$("rhs", Float)) >> Bool
      | ($$("lhs", Byte) & $$("rhs", Byte)) >> Bool
      | ($$("lhs", Bool) & $$("rhs", Bool)) >> Bool
      | ($$("lhs", VoidPtr) & $$("rhs", VoidPtr)) >> Bool
      ;


      auto less = "operator<"s
      | ($$("lhs", Int) & $$("rhs", Int)) >> Bool
      | ($$("lhs", Float) & $$("rhs", Float)) >> Bool
      | ($$("lhs", Byte) & $$("rhs", Byte)) >> Bool
      | ($$("lhs", VoidPtr) & $$("rhs", VoidPtr)) >> Bool
      ;


      auto greater = "operator>"s
      | ($$("lhs", Int) & $$("rhs", Int)) >> Bool
      | ($$("lhs", Float) & $$("rhs", Float)) >> Bool
      | ($$("lhs", Byte) & $$("rhs", Byte)) >> Bool
      | ($$("lhs", VoidPtr) & $$("rhs", VoidPtr)) >> Bool
      ;


      auto less_equal = "operator<="s
      | ($$("lhs", Int) & $$("rhs", Int)) >> Bool
      | ($$("lhs", Float) & $$("rhs", Float)) >> Bool
      | ($$("lhs", Byte) & $$("rhs", Byte)) >> Bool
      | ($$("lhs", VoidPtr) & $$("rhs", VoidPtr)) >> Bool
      ;


      auto greater_equal = "operator>="s
      | ($$("lhs", Int) & $$("rhs", Int)) >> Bool
      | ($$("lhs", Float) & $$("rhs", Float)) >> Bool
      | ($$("lhs", Byte) & $$("rhs", Byte)) >> Bool
      | ($$("lhs", VoidPtr) & $$("rhs", VoidPtr)) >> Bool
      ;


      auto binary_and = "operator&"s
      | ($$("lhs", Int) & $$("lhs", Int)) >> Int
      | ($$("lhs", Byte) & $$("lhs", Byte)) >> Byte
      | ($$("lhs", Bool) & $$("lhs", Bool)) >> Bool
      ;


      auto binary_or = "operator|"s
      | ($$("lhs", Int) & $$("lhs", Int)) >> Int
      | ($$("lhs", Byte) & $$("lhs", Byte)) >> Byte
      | ($$("lhs", Bool) & $$("lhs", Bool)) >> Bool
      ;


      auto unary_negate = "operator~"s
      | ($$("value", Int)) >> Int
      | ($$("value", Byte)) >> Byte
      | ($$("value", Bool)) >> Bool
      ;


      auto increment = "operator++"s
      | ($$("value", Int)) >> Int
      | ($$("value", Float)) >> Float
      ;


      auto decrement = "operator--"s
      | ($$("value", Int)) >> Int
      | ($$("value", Float)) >> Float
      ;


      auto conjunction = "operator&&"s
      | ($$("lhs", Bool) & $$("lhs", Bool)) >> Bool
      ;


      auto disjunction = "operator||"s
      | ($$("lhs", Bool) & $$("lhs", Bool)) >> Bool
      ;


      auto negate = "operator!"s
      | ($$("value", Bool)) >> Bool
      ;


      //*/ Types
      Namespace::S_globalNamespace->define(dynamic_cast<ISymbol*>(Int));
      Namespace::S_globalNamespace->define(dynamic_cast<ISymbol*>(Byte));
      Namespace::S_globalNamespace->define(dynamic_cast<ISymbol*>(Bool));
      Namespace::S_globalNamespace->define(dynamic_cast<ISymbol*>(Float));
      Namespace::S_globalNamespace->define(dynamic_cast<ISymbol*>(Void));
      
      //*/ Operators
      Namespace::S_globalNamespace->define(dynamic_cast<ISymbol*>(plus));
      Namespace::S_globalNamespace->define(dynamic_cast<ISymbol*>(minus));
      Namespace::S_globalNamespace->define(dynamic_cast<ISymbol*>(multiplies));
      Namespace::S_globalNamespace->define(dynamic_cast<ISymbol*>(divides));
      Namespace::S_globalNamespace->define(dynamic_cast<ISymbol*>(modulus));
      Namespace::S_globalNamespace->define(dynamic_cast<ISymbol*>(equal_to));
      Namespace::S_globalNamespace->define(dynamic_cast<ISymbol*>(not_equal_to));
      Namespace::S_globalNamespace->define(dynamic_cast<ISymbol*>(less));
      Namespace::S_globalNamespace->define(dynamic_cast<ISymbol*>(greater));
      Namespace::S_globalNamespace->define(dynamic_cast<ISymbol*>(less_equal));
      Namespace::S_globalNamespace->define(dynamic_cast<ISymbol*>(greater_equal));
      Namespace::S_globalNamespace->define(dynamic_cast<ISymbol*>(binary_and));
      Namespace::S_globalNamespace->define(dynamic_cast<ISymbol*>(binary_or));
      Namespace::S_globalNamespace->define(dynamic_cast<ISymbol*>(unary_negate));
      Namespace::S_globalNamespace->define(dynamic_cast<ISymbol*>(increment));
      Namespace::S_globalNamespace->define(dynamic_cast<ISymbol*>(decrement));
      Namespace::S_globalNamespace->define(dynamic_cast<ISymbol*>(conjunction));
      Namespace::S_globalNamespace->define(dynamic_cast<ISymbol*>(disjunction));
      Namespace::S_globalNamespace->define(dynamic_cast<ISymbol*>(negate));
    }

    return Namespace::S_globalNamespace;
  }

  auto Namespace::get_declaring_symbol_table() const -> ISymbolTable* {
    return this->M_parentNamespace;
  }

  auto Namespace::get_attributes() const -> Attributes {
    throw NotImplementedError{};
  }

  auto Namespace::get_parent() const -> ISymbolTable* {
    return dynamic_cast<ISymbolTable*>(this->M_parentNamespace);
  }
  
  auto Namespace::to_namespace(ISymbol* symbol) -> Namespace* {
    return dynamic_cast<Namespace*>(symbol);
  }

  auto Namespace::is_namespace(ISymbol* symbol) -> bool {
    return dynamic_cast<Namespace*>(symbol) != nullptr;
  }

  auto Namespace::find_or_create_namespace(string_view name) -> Namespace* {
    auto candidate = Namespace::find_namespace(name);
    return candidate != nullptr ? candidate : Namespace::Factory::create(string{ name });
  }

}