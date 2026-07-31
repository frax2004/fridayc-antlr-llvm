#pragma once

namespace friday::inline api::inline pipeline {
  enum class ValueCategory : u8 {
    ILLEGAL,
    LVALUE,
    RVALUE
  };
}