#pragma once

#include <memory>

struct IState; // forward declaration

struct IStateManager {
  virtual void set_next_state(std::unique_ptr<IState> state) = 0;
  virtual ~IStateManager() = default;
};

struct IState {
public:
  IState(IStateManager &state_manager) : m_state_manager(state_manager) {}
  virtual bool do_step() = 0;
  virtual ~IState() = default;

protected:
  IStateManager &m_state_manager;
};

struct ExitState : public IState {
  using IState::IState;
  bool do_step() override { return false; }
};
