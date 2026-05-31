#include <Function.hpp>
#include <SymbolTable.hpp>

namespace friday::inline api::inline typesystem {
  
  Function::Function(Overload& parent, string name, Type& returnType, vector<pair<string, Type*>> parameters)
    : M_owner { &parent }
    , M_parameters {
      parameters 
      | views::transform(&pair<string, Type*>::first) 
      | ranges::to<vector>()
    }
  {
    this->M_signature = (FunctionType*)FunctionType::get(
      returnType,
      parameters
      | views::transform(&pair<string, Type*>::second)
      | ranges::to<vector>()
    );
  }

  auto Function::getParameterName(u64 index) const -> string const& {
    return this->M_parameters.at(index);
  }

  auto Function::getParameter(u64 index) const -> pair<string, Type*> {
    return make_pair(
      this->M_parameters.at(index),
      this->M_signature->getParameterType(index)
    );
  }

  auto Function::getType() -> Type* {
    return this->M_signature;
  }

}