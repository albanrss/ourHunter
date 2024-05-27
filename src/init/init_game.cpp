/*
** EPITECH PROJECT, 2024
** init game
** File description:
** init_game
*/

#include "my.hpp"

game init_game(void)
{
    game data;

    data.texture_main_menu.loadFromFile("assets/main_screen.jpg");
    data.sprite_main_menu.setTexture(data.texture_main_menu);
    return data;
}
