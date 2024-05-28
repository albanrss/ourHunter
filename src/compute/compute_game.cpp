/*
** EPITECH PROJECT, 2024
** compute cpp
** File description:
** compute_game
*/

#include "my.hpp"

void compute_game(class Duck *duck, sf::RenderWindow &window)
{
    (duck)->check_out_screen(window);
    (duck)->move_sprite();
    (duck)->display_sprite(&window);
}
