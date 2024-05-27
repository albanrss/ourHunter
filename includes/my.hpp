/*
** EPITECH PROJECT, 2024
** Vacances_tek1
** File description:
** my
*/

#include <iostream>
#include <SFML/Audio.hpp>
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

int start_app(game_t *data);
//Init
game_t *init_game(void);

#endif /* !MY_HPP_ */
