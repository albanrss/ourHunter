/*
** EPITECH PROJECT, 2024
** ourHunter
** File description:
** init_duck
*/

#include "my.hpp"

img_t *init_duck(void)
{
    img_t *data = new img_t;

    data->texture = new sf::Texture();
    if (!data->texture->loadFromFile("assets/duck_spritesheet.png")) {
        std::cerr << "Failed to load duck sprite sheet!" << std::endl;
        return nullptr;
    }
    data->rect_sprite = sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(110, 110));
    data->sprite = new sf::Sprite();
    data->sprite->setTexture(*(data->texture));
    data->sprite->setOrigin(sf::Vector2f(55, 55));
    data->sprite->setTextureRect(data->rect_sprite);
    data->current_position = sf::Vector2f(55, float((rand() % 1026) + 55));
    data->sprite->setPosition(data->current_position);
    return data;
}

img_t *init_img(std::string path, sf::Vector2f pos)
{
    img_t *data = new img_t;
    sf::Vector2u size_sprite = sf::Vector2u(0, 0);

    data->texture = new sf::Texture;
    if (!data->texture->loadFromFile(path)) {
        std::cerr << "Failed to load sprite" << std::endl;
        return nullptr;
    }
    data->sprite = new sf::Sprite;
    data->sprite->setTexture(*data->texture);
    size_sprite = data->texture->getSize();
    data->sprite->setOrigin(sf::Vector2f(((float)size_sprite.x / 2), ((float)size_sprite.y / 2)));
    data->sprite->setPosition(pos);
    data->current_position = pos;
    return data;
}