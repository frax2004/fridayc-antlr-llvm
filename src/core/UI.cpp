#include <fridayc.hpp>

namespace friday::inline UI {

  auto Textbox::build() -> Widget::Renderer {
    return [&](rl::Rectangle bounds) {
      if(rl::GuiTextBox(bounds, this->buffer.data(), this->buffer.size(), this->editMode)) {
        this->editMode = !this->editMode;
      }
    };
  }

  auto HorizontalLayout(Layout layout) -> void {
    f32 totalWeight = ranges::fold_left(
      layout.children
      | views::transform(&Layout::Component::weight),
      0.0f,
      plus{}
    );

    f32 currentWeight = 0.0f;
    for(auto&& child: layout.children) {
      child.component({ 
        .x = layout.bounds.x + layout.bounds.width * currentWeight, 
        .y = layout.bounds.y, 
        .width = layout.bounds.width * (child.weight/totalWeight), 
        .height = layout.bounds.height
      });
      currentWeight += child.weight/totalWeight;
    }
  }

  
  auto VerticalLayout(Layout layout) -> void {
    f32 totalWeight = ranges::fold_left(
      layout.children
      | views::transform(&Layout::Component::weight),
      0.0f,
      plus{}
    );

    f32 currentWeight = 0.0f;
    for(auto&& child: layout.children) {
      child.component({ 
        .x = layout.bounds.x, 
        .y = layout.bounds.y + layout.bounds.height * currentWeight, 
        .width = layout.bounds.width,
        .height = layout.bounds.height * (child.weight/totalWeight)
      });
      currentWeight += child.weight;
    }
  }
}