#include <fridayc.hpp>

namespace friday::api {
  
  auto less_by_signature::operator()(FunctionType* const& self, vector<Type*> const& rhs) const -> bool {
    auto lhs = ranges::subrange(self->param_begin(), self->param_end());
    return ranges::lexicographical_compare(lhs, rhs);
  }

  auto less_by_signature::operator()(vector<Type*> const& rhs, FunctionType* const& self) const -> bool {
    auto lhs = ranges::subrange(self->param_begin(), self->param_end());
    return ranges::lexicographical_compare(lhs, rhs);
  }

  auto less_by_signature::operator()(FunctionType* const& lhs, FunctionType* const& rhs) const -> bool {
    return ranges::lexicographical_compare(
      ranges::subrange(lhs->param_begin(), lhs->param_end()),
      ranges::subrange(rhs->param_begin(), rhs->param_end())
    );
  }

  
}