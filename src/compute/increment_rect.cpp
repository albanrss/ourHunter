/*
** EPITECH PROJECT, 2024
** increment rect
** File description:
** increment_rect
*/

#include "my.hpp"

void increment_rect(img_t *data)
{
    data->animated->current_frame += 1;
    data->animated->rect_sprite.left += data->animated->rect_sprite.width;
    if (data->animated->rect_sprite.left >= data->animated->rect_sprite.width
        * data->animated->max_frame) {
        data->animated->current_frame = 1;
        data->animated->rect_sprite.left = 0;
    }
    data->sprite->setTextureRect(data->animated->rect_sprite);
}
