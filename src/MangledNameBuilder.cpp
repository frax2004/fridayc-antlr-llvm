#include <MangledNameBuilder.hpp>
#include <Type.hpp>

namespace friday::inline api::inline typesystem {

  MangledNameBuilder::MangledNameBuilder(String name) 
    : M_names { name }
  {}
  
  auto MangledNameBuilder::dot(String name) -> MangledNameBuilder& {
    this->M_names.push_back(name);
    return *this;
  }

  auto MangledNameBuilder::param(Type* type) -> MangledNameBuilder& {
    this->M_argsTypes.push_back(type);
    return *this;
  }

  auto MangledNameBuilder::build() -> String {
    auto mangle = [](String const& name) {
      return "{}{}"_f.format(name.length(), name);
    };

    return "_Z{}{}{}{}"_f.format(
      this->M_names.size() > 1 ? "N" : "",
      this->M_names
      | std::views::transform(mangle)
      | std::views::join_with(""s)
      | std::ranges::to<std::string>(),
      this->M_names.size() > 1 ? "E" : "",
      this->M_argsTypes
      | std::views::transform(Type::getName)
      | std::views::transform(mangle)
      | std::views::join_with(""s)
      | std::ranges::to<std::string>()
    );
  }

}