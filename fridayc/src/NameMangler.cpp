#include <NameMangler.hpp>
#include <Type.hpp>

namespace friday::inline api::inline typesystem {

  NameMangler::NameMangler(string name) 
    : M_names { name }
  {}
  
  auto NameMangler::dot(string name) -> NameMangler& {
    this->M_names.push_back(name);
    return *this;
  }

  auto NameMangler::param(Type* type) -> NameMangler& {
    this->M_argsTypes.push_back(type);
    return *this;
  }

  auto NameMangler::build() -> string {
    auto mangle = [](string_view name) {
      return "{}{}"_f.format(name.length(), name);
    };

    return "_Z{}{}{}{}"_f.format(
      this->M_names.size() > 1 ? "N" : "",
      this->M_names
      | views::transform(mangle)
      | views::join_with(""s)
      | ranges::to<string>(),
      this->M_names.size() > 1 ? "E" : "",
      this->M_argsTypes
      | views::transform(&Type::get_name)
      | views::transform(mangle)
      | views::join_with(""s)
      | ranges::to<string>()
    );
  }

}