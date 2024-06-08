#pragma once

#include "../Configuration.h"
#include "../Game/GameState.h"
#include "../State.h"
#include <iostream>
struct ISelectCommand {
  virtual void execute() = 0;
  virtual ~ISelectCommand() = default;
};

class ChangeStateCommand : public ISelectCommand {
public:
  ChangeStateCommand(IStateManager &state_manager)
      : m_state_manager(state_manager) {}

protected:
  IStateManager &m_state_manager;
};

struct ExitCommand : ChangeStateCommand {
  using ChangeStateCommand::ChangeStateCommand;
  void execute() {
    m_state_manager.set_next_state(
        std::make_unique<ExitState>(m_state_manager));
  }
};

class GameCommand : public ChangeStateCommand {
public:
  using ChangeStateCommand::ChangeStateCommand;
  GameCommand(IStateManager &state_manager, const sf::Color &color)
      : ChangeStateCommand(state_manager) {
    background_color = color;
  }
  void execute() {
    m_state_manager.set_next_state(
        std::make_unique<GameState>(m_state_manager, config::GAME_VIDEO_MODE,
                                    "GameLevel", background_color));
  }

private:
  sf::Color background_color;
};