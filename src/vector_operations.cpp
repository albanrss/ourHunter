/*
** EPITECH PROJECT, 2024
** vector
** File description:
** vector_operations
*/

#include "my.hpp"

sf::Vector2f mult3(sf::Vector2f pos, float val)
{
    return ((sf::Vector2f){pos.x * val, pos.y * val});
}