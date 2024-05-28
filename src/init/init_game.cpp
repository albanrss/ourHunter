/*
** EPITECH PROJECT, 2024
** init game
** File description:
** init_game
*/

#include "my.hpp"

window_t *init_window(void)
{
    window_t *window = new window_t;

    window->window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "OurHunter");
    return window;
}

game_t *init_game(void)
{
    game_t *game = new game_t;

    game->window = init_window();
    game->scene = MAIN_MENU;
    init_main_menu_scene(game);
    init_game_scene(game);
    init_end_scene(game);
    init_settings_scene(game);
    return game;
}
