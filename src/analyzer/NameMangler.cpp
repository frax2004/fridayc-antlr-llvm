#include <fridayc.hpp>


namespace friday::inline api {

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

  static auto mangle(string_view name) -> string {
    using opcode_map_type = unordered_map<string, string, transparent_string_hash, equal_to<>>;
    static opcode_map_type S_opCodes = {
      {"operator+", "pl"}, 
      {"operator-", "mi"}, 
      {"operator*", "ml"}, 
      {"operator/", "dv"}, 
      {"operator%", "rm"},
      {"operator==", "eq"}, 
      {"operator!=", "ne"}, 
      {"operator<", "lt"}, 
      {"operator>", "gt"}, 
      {"operator<=", "le"},
      {"operator>=", "ge"}, 
      {"operator&", "an"}, 
      {"operator|", "or"}, 
      {"operator~", "co"}, 
      {"operator&&", "aa"}, 
      {"operator||", "oo"},
      {"operator!", "nt"}, 
      {"operator++", "pp"}, 
      {"operator--", "mm"},
    };

    if(auto it = S_opCodes.find(name); it != S_opCodes.end()) {
      return it->second;
    } 
    if(name.empty()) {
      return "";
    } else if(name.starts_with('*')) {
      string_view elementTypeName = name;
      u64 dims = 0;
      while(elementTypeName.starts_with('*')) {
        ++dims;
        elementTypeName.remove_prefix(1);
      }

      return format("{:P>{}}{}{}", "", dims, elementTypeName.length(), elementTypeName);
    } else return format("{}{}", name.length(), name);

  };

  auto NameMangler::build() -> string {

    return format(
      "_Z{}{}{}{}",
      this->M_names.size() > 1 and not this->M_names[0].empty() ? "N" : "",
      this->M_names
      | views::transform(mangle)
      | views::join_with(""s)
      | ranges::to<string>(),
      this->M_names.size() > 1 and not this->M_names[0].empty() ? "E" : "",
      this->M_argsTypes
      | views::transform(&Type::get_name)
      | views::transform(mangle)
      | views::join_with(""s)
      | ranges::to<string>()
    );
  }

}