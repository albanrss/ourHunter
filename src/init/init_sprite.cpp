/*
** EPITECH PROJECT, 2024
** EPITECH
** File description:
** init_sprite
*/

#include "my.hpp"

sf::Sprite *init_sprite(string file, sf::Vector2f pos, sf::Vector2f scale)
{
    sf::Sprite *sprite = new sf::Sprite;
    sf::Texture *texture = new sf::Texture;
    sf::Vector2f size;
    sf::FloatRect bounds;

    texture->loadFromFile(file);
    sprite->setTexture(*texture);
    sprite->setPosition(pos);
    sprite->setScale(scale);
    bounds = sprite->getGlobalBounds();
    size.x = bounds.width;
    size.y = bounds.height;
    sprite->setOrigin(size.x / 2, size.y / 2);
    return sprite;
}
