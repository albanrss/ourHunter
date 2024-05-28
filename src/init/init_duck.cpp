/*
** EPITECH PROJECT, 2024
** ourHunter
** File description:
** init_duck
*/

#include "my.hpp"

void init_animated(img_t *data, sf::Vector2i pos, sf::Vector2i size)
{
    animated_t *data_an = new animated_t;
    sf::Vector2u size_picture = data->texture->getSize();

    data_an->max_frame = size_picture.x / size.x;
    data_an->rect_sprite = sf::IntRect(pos, size);
    data_an->current_frame = 1;
    data->sprite->setTextureRect(data_an->rect_sprite);
    data->animated = data_an;
}

img_t *init_img(std::string path, sf::Vector2f pos, sf::Vector2f size)
{
    img_t *data = new img_t;

    data->texture = new sf::Texture;
    if (!data->texture->loadFromFile(path)) {
        std::cerr << "Failed to load sprite" << std::endl;
        return nullptr;
    }
    data->sprite = new sf::Sprite;
    data->sprite->setTexture(*data->texture);
    data->sprite->setOrigin(sf::Vector2f(((float)size.x / 2), ((float)size.y / 2)));
    data->current_position = pos;
    data->sprite->setPosition(pos);
    return data;
}