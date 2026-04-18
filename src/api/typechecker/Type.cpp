#include "api/typechecker/Type.hpp"
#include "api/parser/FridayScanner.h"

namespace friday::inline api::inline typechecker {

  Type::Type(VisibilityModifier visibility) noexcept
    : M_visibility { visibility }
  {}

  auto Type::getVisibility() const noexcept -> VisibilityModifier {
    return this->M_visibility;
  }
  
  auto Type::getUnaryOperatorName(u64 oper, Type* T) noexcept -> String {
    switch(oper) {
      case FridayScanner::PLUS: return "operator+({})"_f.format(T->getName());
      case FridayScanner::MINUS: return "operator-({})"_f.format(T->getName());
      default: return "<invalid-operator>({})"_f.format(T->getName());
    }

    std::unreachable();
  }

  
  auto Type::getBinaryOperatorName(u64 oper, Type* T, Type* U) noexcept -> String {
    switch(oper) {
      case FridayScanner::PLUS: return "operator+({}, {})"_f.format(T->getName(), U->getName());
      case FridayScanner::MINUS: return "operator-({}, {})"_f.format(T->getName(), U->getName());
      case FridayScanner::STAR: return "operator*({}, {})"_f.format(T->getName(), U->getName());
      case FridayScanner::SLASH: return "operator/({}, {})"_f.format(T->getName(), U->getName());
      case FridayScanner::MODULO: return "operator%({}, {})"_f.format(T->getName(), U->getName());
      default: return "<invalid-operator>({})"_f.format(T->getName(), U->getName());
    }

    std::unreachable();
  }
}