#pragma once

#include "Menu.h"
#include "../State.h"
#include "../WindowKeeper.h"

class SelectState : public IState, public IWindowKeeper {
public:
	SelectState(IStateManager& state_manager, const sf::VideoMode& mode, const char* window_title);
	bool do_step() override;
private:
	void event_handling() override;
	void update() override;
	void render() override;
private:
	Menu m_menu;
};