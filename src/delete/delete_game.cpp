/*
** EPITECH PROJECT, 2024
** ourHunter
** File description:
** delete_game
*/

#include "my.hpp"

void delete_game(class Duck *duck)
{
    duck->~Duck();
}
