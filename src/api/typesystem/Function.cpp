#include "api/typesystem/Function.hpp"

namespace friday::inline api::inline typesystem {
  
  Function::Function(SymbolTable* parent, String name, Type* returnType, Vector<std::pair<String, Type*>> parameters)
    : M_declaringSymbolTable { parent }
    , M_name { std::move(name) }
    , M_parameters {
      parameters 
      | std::views::transform(&std::pair<String, Type*>::first) 
      | std::ranges::to<std::vector>()
    }
  {
    this->M_signature = (FunctionType*)FunctionType::get(
      returnType,
      parameters
      | std::views::transform(&std::pair<String, Type*>::second)
      | std::ranges::to<std::vector>()
    );
  }

  auto Function::getParameterName(u64 index) const -> String const& {
    return this->M_parameters.at(index);
  }

  auto Function::getParameter(u64 index) const -> std::pair<String, Type*> {
    return std::make_pair(
      this->M_parameters.at(index),
      this->M_signature->getParameterType(index)
    );
  }

}