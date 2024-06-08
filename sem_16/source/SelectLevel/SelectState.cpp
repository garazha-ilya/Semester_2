#include "SelectState.h"
#include "../Configuration.h"

#include <SFML/Graphics.hpp>

SelectState::SelectState(IStateManager &state_manager,
                         const sf::VideoMode &mode, const char *window_title)
    : IState(state_manager), IWindowKeeper(mode, window_title),
      m_menu(state_manager) {}

bool SelectState::do_step() {
  event_handling();
  update();
  render();
  return true;
}

void SelectState::event_handling() {
  sf::Event event;
  while (m_window.pollEvent(event))
    switch (event.type) {
    case sf::Event::Closed:
      m_state_manager.set_next_state(
          std::make_unique<ExitState>(m_state_manager));
      break;
    }
}

void SelectState::update() {
  m_menu.process_mouse(
      m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window)),
      sf::Mouse::isButtonPressed(sf::Mouse::Left));
}

void SelectState::render() {
  m_window.clear(config::SELECT_LEVEL_BACKGROUND_COLOR);
  m_menu.draw_into(m_window);
  m_window.display();
}