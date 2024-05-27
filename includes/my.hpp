/*
** EPITECH PROJECT, 2024
** Vacances_tek1
** File description:
** my
*/

#include "ducks.hpp"
#include <iostream>
#include <SFML/Audio.hpp>
#include <cmath>
#include <SFML/Graphics.hpp>

#ifndef MY_HPP_
    #define MY_HPP_

struct main_menu_t {
    sf::Texture texture_main_menu;
    sf::Sprite sprite_main_menu;
};

struct game_t {
    main_menu_t *main_menu;
};

int start_app(class Duck *duck1);
//Init

//Vectorization
sf::Vector2f mult3(sf::Vector2f pos, float val);

#endif /* !MY_HPP_ */
