#pragma once

#include <SFML/Graphics.hpp>

namespace config {
// Общие настройки приложения:
const unsigned int FRAME_RATE_LIMIT = 60;
// Кнопки:
const sf::Vector2f BUTTON_SIZE = {250, 100};
const size_t BUTTON_FONT_SIZE = static_cast<size_t>(BUTTON_SIZE.y / 1.5f);
const float BUTTON_FRAME_THICKNESS = 2.0f;
const char FONT_FILE[] = "Calibri-Light.ttf";
// Уровни:
const char SELECT_LEVEL_TITLE[] = "Select Level";
const sf::VideoMode SELECT_LEVEL_VIDEO_MODE{400, 600};
const char BUTTON_TEXT_EASY[] = "Easy";
const char BUTTON_TEXT_MEDIUM[] = "Medium";
const char BUTTON_TEXT_HARD[] = "Hard";
const char BUTTON_TEXT_EXIT[] = "Exit";
// const sf::VideoMode GAME_VIDEO_MODE{ 380, 220 };
// const sf::VideoMode GAME_VIDEO_MODE{ 580, 320 };
const sf::VideoMode GAME_VIDEO_MODE{1080, 780};
const char EASY_GAME_TITLE[] = "Level: Easy";
const char MEDIUM_GAME_TITLE[] = "Level: Medium";
const char HARD_GAME_TITLE[] = "Level: Hard";
const float EASY_GAME_ENEMY_RATIO = 0.0f;
const float MEDIUM_GAME_ENEMY_RATIO = 0.03f;
const float HARD_GAME_ENEMY_RATIO = 0.07f;
const float ROOM_SIZE = 50;
const float GAME_ENEMY_SIZE = ROOM_SIZE * 0.7;
const float GAME_FOOD_SIZE = ROOM_SIZE * 0.2;
// Управление:
const float GAME_PACMAN_SIZE = ROOM_SIZE * 0.8;
const sf::Keyboard::Key KEY_LEFT = sf::Keyboard::A;
const sf::Keyboard::Key KEY_RIGHT = sf::Keyboard::D;
const sf::Keyboard::Key KEY_UP = sf::Keyboard::W;
const sf::Keyboard::Key KEY_DOWN = sf::Keyboard::S;
// Цвета:
#ifdef WHITE_THEME
const sf::Color BUTTON_COLOR_TEXT{0, 0, 0};
const sf::Color BUTTON_COLOR_FILL{180, 180, 180};
const sf::Color BUTTON_COLOR_SELECTION{255, 180, 180};
const sf::Color BUTTON_COLOR_FRAME{0, 0, 0};
const sf::Color SELECT_LEVEL_BACKGROUND_COLOR{230, 230, 230};
const sf::Color GAME_COLOR_BACKGROUND_INGAME{230, 230, 230};
const sf::Color GAME_COLOR_BACKGROUND_WIN{0, 255, 0};
const sf::Color GAME_COLOR_BACKGROUND_LOST{255, 0, 0};
const sf::Color GAME_COLOR_PACMAN{250, 150, 0};
const sf::Color GAME_COLOR_ROOM{255, 255, 255};
const sf::Color GAME_COLOR_WALL{0, 0, 0};
const sf::Color GAME_FOOD_COLOR{0, 200, 100};
const sf::Color GAME_ENEMY_COLOR{255, 50, 0};
#endif
#ifdef BLACK_THEME
const sf::Color BUTTON_COLOR_TEXT{255, 255, 255};
const sf::Color BUTTON_COLOR_FILL{0, 0, 0};
const sf::Color BUTTON_COLOR_SELECTION{50, 50, 100};
const sf::Color BUTTON_COLOR_FRAME{0, 0, 255};
const sf::Color SELECT_LEVEL_BACKGROUND_COLOR{25, 25, 25};
const sf::Color GAME_COLOR_BACKGROUND_INGAME{50, 50, 50};
const sf::Color GAME_COLOR_BACKGROUND_WIN{0, 100, 0};
const sf::Color GAME_COLOR_BACKGROUND_LOST{100, 0, 0};
const sf::Color GAME_COLOR_PACMAN{250, 250, 0};
const sf::Color GAME_COLOR_ROOM{0, 0, 0};
const sf::Color GAME_COLOR_WALL{0, 0, 255};
const sf::Color GAME_FOOD_COLOR{0, 200, 100};
const sf::Color GAME_ENEMY_COLOR{255, 50, 0};
#endif
} // namespace config