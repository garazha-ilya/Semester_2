#pragma once

#include "../State.h"
#include "../WindowKeeper.h"

class GameState : public IState, public IWindowKeeper {
public:
  GameState(IStateManager &state_manager, const sf::VideoMode &mode,
            const char *window_title, const sf::Color &color);
  bool do_step() override;

private:
  void event_handling() override;
  void update() override;
  void render() override;

private:
  void process_key_pressed(sf::Keyboard::Key code);
  void process_entities_interactions();

private:
  sf::RectangleShape Background;
};