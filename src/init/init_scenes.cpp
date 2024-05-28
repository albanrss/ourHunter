/*
** EPITECH PROJECT, 2024
** EPITECH
** File description:
** init_scenes
*/

#include "my.hpp"

void init_main_menu_scene(game_t *game)
{
    contents_t *contents = new contents_t;

    contents->bg = new sf::Sprite;
    contents->container = new sf::Sprite;
    contents->buttons = new button_t[2];
    game->scenes[MAIN_MENU] = new Scene(contents);
}

void init_game_scene(game_t *game)
{
    contents_t *contents = new contents_t;

    contents->bg = new sf::Sprite;
    contents->container = new sf::Sprite;
    contents->infos_containers = new sf::Sprite[3];
    contents->infos_texts = new sf::Text[3];
    contents->buttons = new button_t[1];
    game->scenes[GAME] = new Scene(contents);
}

void init_end_scene(game_t *game)
{
    contents_t *contents = new contents_t;

    contents->bg = new sf::Sprite;
    contents->container = new sf::Sprite;
    contents->infos_containers = new sf::Sprite[1];
    contents->infos_texts = new sf::Text[1];
    contents->buttons = new button_t[1];
    game->scenes[END] = new Scene(contents);
}

void init_settings_scene(game_t *game)
{
    contents_t *contents = new contents_t;

    contents->bg = new sf::Sprite;
    contents->container = new sf::Sprite;
    contents->infos_containers = new sf::Sprite[1];
    contents->infos_texts = new sf::Text[1];
    contents->buttons = new button_t[1];
    game->scenes[SETTINGS] = new Scene(contents);
}
