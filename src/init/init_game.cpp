/*
** EPITECH PROJECT, 2024
** init game
** File description:
** init_game
*/

#include "my.hpp"

main_menu_t *init_main_menu(void)
{
    main_menu_t *data = new main_menu_t;

    data->texture_main_menu.loadFromFile("assets/main_screen.jpg");
    data->sprite_main_menu.setTexture(data->texture_main_menu);
    return data;
}

game_t *init_game(void)
{
    game_t *game = new game_t;

    game->main_menu = init_main_menu();
    return game;
}
