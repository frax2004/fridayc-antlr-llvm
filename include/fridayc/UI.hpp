#pragma once
#include "Common.hpp"

namespace friday::inline UI {
  struct Widget {
    using Renderer = function<void(rl::Rectangle)>;
    virtual auto build() -> Renderer = 0;
  };

  struct Layout {
    struct Component {
      f32 weight = 1.0f;
      Widget::Renderer component { [](rl::Rectangle) {} };
    };

    rl::Rectangle bounds;
    vector<Component> children;
  };


  struct Textbox : Widget {
    array<i8, 256> buffer = { };
    bool editMode = false;

    auto build() -> Widget::Renderer;
  };

  auto HorizontalLayout(Layout layout) -> void;
  auto VerticalLayout(Layout layout) -> void;
}