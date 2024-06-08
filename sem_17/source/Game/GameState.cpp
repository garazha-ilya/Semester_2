#include "GameState.h"

#include "../Configuration.h"
#include "../SelectLevel/SelectState.h"

GameState::GameState(IStateManager &state_manager, const sf::VideoMode &mode,
                     const char *window_title, const sf::Color &color)
    : IState(state_manager), IWindowKeeper(mode, window_title) {
  Background.setFillColor(color);
  Background.setSize(sf::Vector2f(mode.width, mode.height));
}

bool GameState::do_step() {
  event_handling();
  update();
  render();
  return true;
}

void GameState::event_handling() {
  sf::Event event;
  while (m_window.pollEvent(event))
    switch (event.type) {
    case sf::Event::Closed:
      m_state_manager.set_next_state(std::make_unique<SelectState>(
          m_state_manager, config::SELECT_LEVEL_VIDEO_MODE,
          config::SELECT_LEVEL_TITLE));
      break;
    }
}
void GameState::update() {}

void GameState::render() {
  m_window.draw(Background);
  m_window.display();
}
