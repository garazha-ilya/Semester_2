#include "Button.h"

#include "../Configuration.h"

MyFont::MyFont() {
  if (!m_font.loadFromFile(config::FONT_FILE))
    throw std::runtime_error("Can't load font!\n");
}

void Button::set(sf::Vector2f pos, sf::Vector2f button_size,
                 const std::string &text, size_t font_size,
                 std::unique_ptr<ISelectCommand> &&ptr_command) {
  // Сформируем текст:
  m_text.setFont(MyFont::Instance());
  m_text.setString(text);
  m_text.setCharacterSize(font_size);
  m_text.setFillColor(config::BUTTON_COLOR_TEXT);
  m_text.setStyle(sf::Text::Bold);
  // Отцентруем текст:
  sf::FloatRect text_rect = m_text.getLocalBounds();
  m_text.setOrigin(text_rect.left + text_rect.width / 2.0f,
                   text_rect.top + text_rect.height / 2.0f);
  m_text.setPosition(pos);
  // Сформируем четырёхугольник с контуром:
  m_rectangle.setSize(button_size);
  m_rectangle.setOrigin(m_rectangle.getSize().x / 2.0f,
                        m_rectangle.getSize().y / 2.0f);
  m_rectangle.setFillColor(config::BUTTON_COLOR_FILL);
  m_rectangle.setPosition(pos);
  m_rectangle.setOutlineColor(config::BUTTON_COLOR_FRAME);
  m_rectangle.setOutlineThickness(config::BUTTON_FRAME_THICKNESS);
  // Зададим команду:
  m_ptr_command = std::move(ptr_command);
}

void Button::draw_into(sf::RenderWindow &window) const {
  window.draw(m_rectangle);
  window.draw(m_text);
}

bool Button::is_position_in(sf::Vector2f pos) {
  return m_rectangle.getGlobalBounds().contains(pos);
}

void Button::select() {
  m_is_selected = true;
  m_rectangle.setFillColor(config::BUTTON_COLOR_SELECTION);
}

void Button::unselect() {
  m_is_selected = false;
  m_rectangle.setFillColor(config::BUTTON_COLOR_FILL);
}

bool Button::is_selected() const { return m_is_selected; }

void Button::push() { m_ptr_command->execute(); }