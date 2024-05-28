/*
** EPITECH PROJECT, 2024
** ourHunter
** File description:
** delete_img
*/

#include "my.hpp"

void delete_img(img_t *data)
{
    delete data->sprite;
    delete data->texture;
    delete data;
}
