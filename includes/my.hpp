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

int start_app(class Duck *data);
// Init
img_t *init_duck(void);
time2_t *init_time(void);

// Analyze
void analyze_envents(class Duck *duck, sf::RenderWindow &window);

// Vectorization
sf::Vector2f mult3(sf::Vector2f pos, float val);

// Delete
void delete_img(img_t *data);

#endif /* !MY_HPP_ */
