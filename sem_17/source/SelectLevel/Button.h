#pragma once

#include "../Drawable.h"
#include "SelectCommand.h"

class MyFont {
public:
  MyFont(const MyFont &) = delete;
  MyFont &operator=(const MyFont &) = delete;
  static sf::Font &Instance() {
    static MyFont instance;
    return instance.m_font;
  }

private:
  MyFont();
  sf::Font m_font;
};

struct Button : IDrawable {
public:
  Button() = default;
  void set(sf::Vector2f pos, sf::Vector2f button_size, const std::string &text,
           size_t font_size, std::unique_ptr<ISelectCommand> &&ptr_command);

public:
  void draw_into(sf::RenderWindow &window) const override;
  bool is_position_in(sf::Vector2f pos);
  void select();
  void unselect();
  bool is_selected() const;
  void push();

private:
  sf::Text m_text;
  sf::RectangleShape m_rectangle;
  bool m_is_selected = true;
  std::unique_ptr<ISelectCommand> m_ptr_command;
};
