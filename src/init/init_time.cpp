/*
** EPITECH PROJECT, 2024
** ourHunter
** File description:
** init_time
*/

#include "my.hpp"

time2_t *init_time(void)
{
    time2_t *data = new time2_t;

    data->clock = new sf::Clock;
    data->seconds = 0;
    return data;
}
