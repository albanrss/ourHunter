/*
** EPITECH PROJECT, 2024
** Vacances_tek1
** File description:
** my
*/

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <cmath>
#include <vector>
#include "duckimpact.hpp"
#include "ducks.hpp"
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
img_t *init_img(std::string path, sf::Vector2f pos, sf::Vector2f size);
void init_animated(img_t *data, sf::Vector2i pos, sf::Vector2i size);
time2_t *init_time(void);

// Analyze events
void analyze_events(class Duck *duck, sf::RenderWindow &window);

// Compute fct
void compute_game(class Duck *duck, sf::RenderWindow &window);
void increment_rect(img_t *data);

// Vectorization mutipli a vector with a value
sf::Vector2f mult3(sf::Vector2f pos, float val);

// Delete img
void delete_img(img_t *data);
void delete_time(time2_t *data);
void delete_game(class Duck *duck);

#endif /* !MY_HPP_ */
