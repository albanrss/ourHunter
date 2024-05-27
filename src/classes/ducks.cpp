/*
** EPITECH PROJECT, 2024
** duck.cpp
** File description:
** ducks
*/

#include "my.hpp"
#include <iostream>

Duck::Duck()
{
    Duck_clock = new sf::Clock();
    Duck_texture = new sf::Texture();
    Duck_sprite = new sf::Sprite();
    current_position = sf::Vector2f({0, 0});
    rect_sprite = sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(110, 110));
    Duck_texture->loadFromFile("./assets/duck_spritesheet.png");
    Duck_sprite->setTexture(*Duck_texture);
    Duck_sprite->setTextureRect(rect_sprite);
    Duck_sprite->setPosition(current_position);
    flappy_time = 200;
    speed = 0.1;
    random_dir = (rand() % 3 + 1) * 1000;
    change_dir();
}

void Duck::change_dir(void)
{
    update_position();
    int x = rand() % 1920 + current_position.x;
    int y = rand() % 1080;

    speed = double(rand() % 5 + 1) / 10;
    update_position();
    angle = atan2(y - current_position.y, x - current_position.x);
    dir_vector = sf::Vector2f({(float) cos(angle), (float) sin(angle)});
}

void Duck::update_position(void)
{
    current_position =  Duck_sprite->getPosition();
}

void Duck::display_sprite(sf::RenderWindow &window)
{
    window.draw(*Duck_sprite);
}

void Duck::update_clock(void)
{
    sf::Time time = Duck_clock->getElapsedTime();

    elapsed_time = time.asMilliseconds();
    Duck_clock->restart();
}

void Duck::animate_sprite(void)
{
    flappy_time -= elapsed_time;

    if (flappy_time <= 0) {
        flappy_time = 200;
        if (rect_sprite.left == 220)
            rect_sprite.left = 0;
        else
            rect_sprite.left += 110;
    }
    Duck_sprite->setTextureRect(rect_sprite);
}

void Duck::move_sprite(void)
{
    update_clock();
    update_position();

    animate_sprite();
    random_dir -= elapsed_time;
    if (random_dir <= 0) {
        random_dir = (double)(rand() % 3 + 1) * 1000;
        change_dir();
    }
    Duck_sprite->move(mult3(dir_vector, elapsed_time * speed));
}

Duck::~Duck() {
    delete Duck_sprite;
    delete Duck_texture;
    delete Duck_clock;
}
