#pragma once

#include "../State.h"
#include "Button.h"

#include <array>

class Menu : IDrawable {
public:
  Menu(IStateManager &state_manager);
  void process_mouse(sf::Vector2f pos, bool is_pressed);
  void draw_into(sf::RenderWindow &window) const override;

private:
  std::array<Button, 4> m_buttons;
};
