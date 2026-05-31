#include <Symbol.hpp>

#include <Console.hpp>
#include <OperationNotSupportedError.hpp>

namespace friday::inline api::inline typesystem {
  auto ISymbol::getDemangledId(String const& id) -> String {
    return rtti::demangle(id.data())
    | std::views::split("::"s)
    | std::views::join_with("."s)
    | std::ranges::to<std::string>();
  }
}
