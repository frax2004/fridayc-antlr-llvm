#include <MangledNameBuilder.hpp>
#include <Type.hpp>

namespace friday::inline api::inline typesystem {

  MangledNameBuilder::MangledNameBuilder(string name) 
    : M_names { name }
  {}
  
  auto MangledNameBuilder::dot(string name) -> MangledNameBuilder& {
    this->M_names.push_back(name);
    return *this;
  }

  auto MangledNameBuilder::param(Type* type) -> MangledNameBuilder& {
    this->M_argsTypes.push_back(type);
    return *this;
  }

  auto MangledNameBuilder::build() -> string {
    auto mangle = [](string const& name) {
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
      | views::transform(Type::getName)
      | views::transform(mangle)
      | views::join_with(""s)
      | ranges::to<string>()
    );
  }

}