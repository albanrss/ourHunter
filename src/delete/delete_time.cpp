/*
** EPITECH PROJECT, 2024
** delete.cpp
** File description:
** delete_time
*/

#include "my.hpp"

void delete_time(time2_t *data)
{
    delete data->clock;
    delete data;
}
