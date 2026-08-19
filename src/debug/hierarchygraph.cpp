#include <fridayc.hpp>

namespace friday::inline debug {

  enum Icons : u32 {
    SIGNATURE,
    POINTER_TYPE,
    OVERLOAD,
    ARRAY_TYPE,
    STRUCT,
    NAMESPACE,
  };

  consteval static auto rgb(u8 r, u8 g, u8 b) -> rl::Color {
    return { r, g, b, 255 };
  }

  consteval static auto rgba(u8 r, u8 g, u8 b, u8 a) -> rl::Color {
    return { r, g, b, a };
  }

  namespace theme {
    constexpr rl::Color NAMESPACE_PRIMARY = rgb(247, 125, 18);
    constexpr rl::Color NAMESPACE_SECONDARY = rgba(247, 125, 18, 235);
    array<rl::Texture, 7> ICONS { };
  };

  static auto draw_namespace_icon(rl::Vector2 p, float r) -> void {
    using Center = rl::Vector2;
    using Icon = rl::Texture;

    Center center = { p.x + r, p.y + r };
    Icon icon = theme::ICONS[Icons::NAMESPACE];

    rl::DrawCircleV(center, r, theme::NAMESPACE_PRIMARY);
    rl::DrawCircleLinesV(center, r, theme::NAMESPACE_SECONDARY);
    rl::DrawTextureV(
      icon, 
      Center{ 
        center.x - icon.width/2, 
        center.y - icon.height/2 
      }, 
      rl::WHITE
    );

  }
  
  
  auto show_hierarchy_graph() -> void {
    // rl::SetConfigFlags(rl::FLAG_WINDOW_RESIZABLE);
    rl::InitWindow(1200, 1800, "Fridayc Debugger :: Hierarchy Graph");
    rl::SetTargetFPS(60);

    // auto to_icon_path = [](u64 i) { return format("res/icon{}.png", i); };
    // auto load_icon = [](string path) { return rl::LoadTexture(path.c_str()); };

    // auto icons = views::iota(0ULL, theme::ICONS.size())
    // | views::transform(to_icon_path)
    // | views::transform(load_icon);

    // ranges::copy(icons, theme::ICONS.begin());

    while(not rl::WindowShouldClose()) {
      rl::BeginDrawing();
      rl::ClearBackground(rl::BLACK);
      // draw_namespace_icon({50, 50}, 20);
      rl::EndDrawing();
    }

    // ranges::for_each(theme::ICONS, &rl::UnloadTexture);
    rl::CloseWindow();
  }
}