#pragma once
#include <SFML/Graphics.hpp>

class Button {
public:
	Button(float x, float y) {
		m_rectangle.setSize({ x, y });
		m_rectangle.setOrigin({ x / 2, y / 2 });
		m_rectangle.setFillColor(sf::Color::Green);
		m_rectangle.setOutlineThickness(x/100);
		m_rectangle.setOutlineColor(sf::Color::Yellow);
	};
	void jump(sf::Vector2u limits) { m_rectangle.setPosition(rand() % limits.x, rand() % limits.y); }
	void draw_into(sf::RenderWindow& window) { window.draw(m_rectangle); }
	bool is_position_in(sf::Vector2f position) {
		return m_rectangle.getGlobalBounds().contains(position);
	}
private:
	sf::RectangleShape m_rectangle;
};