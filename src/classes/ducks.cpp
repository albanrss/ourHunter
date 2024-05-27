/*
** EPITECH PROJECT, 2024
** duck.cpp
** File description:
** ducks
*/

#include "my.hpp"

Duck::Duck() {
    Duck_texture = new sf::Texture();
    Duck_sprite = new sf::Sprite();
    current_position = sf::Vector2f({0, 0});
    Duck_texture->loadFromFile("./assets/duck_spritesheet.png");
    Duck_sprite->setTexture(*Duck_texture);
    Duck_sprite->setPosition(current_position);
}

void Duck::refresh_position(sf::Vector2f new_position) {
    current_position = new_position;
    Duck_sprite->setPosition(current_position);
}

void Duck::display_sprite(sf::RenderWindow &window) {
    window.draw(*Duck_sprite);
}

Duck::~Duck() {
    delete Duck_sprite;
    delete Duck_texture;
}
