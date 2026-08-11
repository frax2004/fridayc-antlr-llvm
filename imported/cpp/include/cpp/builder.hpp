#pragma once


namespace cpp {

  template<class T>
  struct Builder {
    virtual ~Builder() = default;
    virtual auto build() -> T = 0;
  };

}