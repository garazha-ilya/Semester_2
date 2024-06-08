#pragma once

#include "State.h"

#include <memory>

class Application: public IStateManager {
public:
	Application();
	int run();
private:
	void set_next_state(std::unique_ptr<IState> ptr_state) override;
	void apply_deffer_state_change();
private:
	std::unique_ptr<IState> m_ptr_state_current;
	std::unique_ptr<IState> m_ptr_state_next;
};
