#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

struct IDrawable {
  virtual void draw_into(sf::RenderWindow &window) const = 0;
  virtual ~IDrawable() = default;
};

struct IPreparable : IDrawable {
  virtual void prepare_for_drawing() = 0;
};