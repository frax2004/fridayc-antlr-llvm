#include <fridayc.hpp>


namespace friday::inline debug {
  auto show_debugger() -> void {
    rl::SetConfigFlags(rl::FLAG_WINDOW_RESIZABLE);
    rl::InitWindow(1200, 800, "Fridayc Debugger");
    rl::SetTargetFPS(60);

    rl::Font font = rl::LoadFont("c:\\WINDOWS\\Fonts\\COUR.TTF");
    rl::Style style = rl::Style::GetTerminalStyle();

    Textbox cmd { };

    rl::GuiSetFont(font);
    rl::GuiLoadStyleFromMemory(style.ptr, style.len);
    rl::GuiSetStyle(
      rl::GuiControl::TEXTBOX, 
      rl::GuiControlProperty::BASE_COLOR_PRESSED, 
      rl::GuiGetStyle(
        rl::GuiControl::TEXTBOX, 
        rl::GuiControlProperty::BASE_COLOR_DISABLED
      )
    );

    while(not rl::WindowShouldClose()) {
      rl::BeginDrawing();
      rl::ClearBackground(rl::BLACK);

      VerticalLayout({
        .bounds = rl::GetWindowBounds(), 
        .children = {
          {
            .weight = .95,
            .component = [&](rl::Rectangle bounds) {
              HorizontalLayout({
                .bounds = bounds,
                .children = {
                  {
                    .weight = .75,
                    .component = [&](rl::Rectangle bounds) {
                      rl::GuiPanel(bounds, nullptr);
                    }
                  },
                  {
                    .weight = .25,
                    .component = [&](rl::Rectangle bounds) {
                      rl::GuiPanel(bounds, nullptr);
                    }
                  }
                }
              });
            }
          },
          {
            .weight = .05,
            .component = [&](rl::Rectangle bounds) {
              HorizontalLayout({
                .bounds = bounds,
                .children = {
                  {
                    .weight = .8,
                    .component = cmd.build()
                  },
                  {
                    .weight = .2,
                    .component = [&](rl::Rectangle bounds) {
                      rl::GuiLabelButton(bounds, "Submit");
                    }
                  }
                }
              });
            }
          }
        }
      });

      rl::EndDrawing();
    }

    rl::UnloadFont(font);
    rl::CloseWindow();
  }
}