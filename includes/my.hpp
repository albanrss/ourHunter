/*
** EPITECH PROJECT, 2024
** Vacances_tek1
** File description:
** my
*/

#include "ducks.hpp"
#include "duckimpact.hpp"
#include <iostream>
#include <SFML/Audio.hpp>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <vector>

#ifndef MY_HPP_
    #define MY_HPP_

struct main_menu_t {
    sf::Texture texture_main_menu;
    sf::Sprite sprite_main_menu;
};

struct game_t {
    main_menu_t *main_menu;
};

// Start app
int start_app(class Duck *data);

/// Init
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
