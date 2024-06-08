#pragma once

#include "Configuration.h"

#include <SFML/Graphics.hpp>

class IWindowKeeper {
public:
	IWindowKeeper(const sf::VideoMode& mode, const char* window_title): m_window(mode, window_title) {
		m_window.setFramerateLimit(config::FRAME_RATE_LIMIT);
		m_window.setKeyRepeatEnabled(false); 
	}
	~IWindowKeeper() = default;
protected:
	virtual void event_handling() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
protected:
	sf::RenderWindow m_window;
};