#include "Menu.h"

#include "../Configuration.h"

Menu::Menu(IStateManager &state_manager) {
  std::unique_ptr<ChangeStateCommand> ptr_command;
  sf::Vector2f pos;

  ptr_command = std::make_unique<GameCommand>(state_manager, sf::Color::Red);
  pos = {config::SELECT_LEVEL_VIDEO_MODE.width / 2.0f,
         config::SELECT_LEVEL_VIDEO_MODE.height / 5.0f};
  m_buttons[0].set(pos, config::BUTTON_SIZE, config::BUTTON_TEXT_EASY,
                   config::BUTTON_FONT_SIZE, std::move(ptr_command));

  ptr_command = std::make_unique<GameCommand>(state_manager, sf::Color::Green);
  pos = {pos.x, pos.y + config::SELECT_LEVEL_VIDEO_MODE.height / 5.0f};
  m_buttons[1].set(pos, config::BUTTON_SIZE, config::BUTTON_TEXT_MEDIUM,
                   config::BUTTON_FONT_SIZE, std::move(ptr_command));

  ptr_command = std::make_unique<GameCommand>(state_manager, sf::Color::Blue);
  pos = {pos.x, pos.y + config::SELECT_LEVEL_VIDEO_MODE.height / 5.0f};
  m_buttons[2].set(pos, config::BUTTON_SIZE, config::BUTTON_TEXT_HARD,
                   config::BUTTON_FONT_SIZE, std::move(ptr_command));

  ptr_command = std::make_unique<ExitCommand>(state_manager);
  pos = {pos.x, pos.y + config::SELECT_LEVEL_VIDEO_MODE.height / 5.0f};
  m_buttons[3].set(pos, config::BUTTON_SIZE, config::BUTTON_TEXT_EXIT,
                   config::BUTTON_FONT_SIZE, std::move(ptr_command));
}

void Menu::process_mouse(sf::Vector2f pos, bool is_pressed) {
  for (Button &button : m_buttons)
    if (button.is_position_in(pos)) {
      if (is_pressed)
        button.push();
      else
        button.select();
    } else
      button.unselect();
}

void Menu::draw_into(sf::RenderWindow &window) const {
  for (const Button &button : m_buttons)
    button.draw_into(window);
}