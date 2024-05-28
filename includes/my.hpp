/*
** EPITECH PROJECT, 2024
** Vacances_tek1
** File description:
** my
*/

#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "scene.hpp"

#ifndef MY_HPP_
    #define MY_HPP_

    #define NBR_SCENES 4

enum scene_e {
    MAIN_MENU,
    GAME,
    END,
    SETTINGS
};

typedef struct window_s {
    sf::RenderWindow *window;
} window_t;

struct game_t {
    enum scene_e scene;
    window_t *window;
    Scene *scenes[NBR_SCENES];
};

int start_app(game_t *data);

// Init
game_t *init_game(void);
void init_main_menu_scene(game_t *game);
void init_game_scene(game_t *game);
void init_end_scene(game_t *game);
void init_settings_scene(game_t *game);
sf::Sprite *init_sprite(string file, sf::Vector2f pos, sf::Vector2f scale);
button_t *init_button(void (*callback)(void), sf::Vector2f pos, sf::Vector2f size);
sf::Text *init_text(string str, sf::Vector2f pos, sf::Font font, int size, sf::Color color);

#endif /* !MY_HPP_ */
