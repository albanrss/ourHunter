/*
** EPITECH PROJECT, 2024
** main
** File description:
** main
*/

#include "my.hpp"

int main(void)
{
    game_t *data_game = init_game();
    class Duck *data = new Duck;

    srand(time(NULL));
    start_app(data);
}
