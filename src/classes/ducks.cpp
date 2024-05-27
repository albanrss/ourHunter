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
    is_dead = false;
    dead_duck = new DuckImpact;
    Duck_clock = new sf::Clock();
    Duck_texture = new sf::Texture();
    Duck_sprite = new sf::Sprite();
    Duck_image = new sf::Image();
    Duck_sprite->setOrigin(sf::Vector2f(55, 55));
    current_position = sf::Vector2f({55, float ((rand() % 1026) + 55)});
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
    int x = rand() % 1865 + 55 + current_position.x;
    int y = rand() % 1026 + 55;

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
    if (is_dead)
        dead_duck->display_sprites(window);
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
    if (is_dead)
        dead_duck->move_sprite();
}

void Duck::reset_pos(void)
{
    sf::Vector2f pos = sf::Vector2f(0, (float)(rand() % 700));

    change_dir();
    Duck_sprite->setPosition(pos);
}

void Duck::check_out_screen(sf::RenderWindow &window)
{
    sf::Vector2u size_window = window.getSize();
    sf::Vector2f pos_sprite = Duck_sprite->getPosition();
    sf::FloatRect rect_window = sf::FloatRect(sf::Vector2f{0, 0},
        sf::Vector2f{(float)size_window.x, (float)size_window.y});

    if (sf::FloatRect(Duck_sprite->getGlobalBounds()).intersects(rect_window)
        == false) {
        reset_pos();
    }
    if (is_dead && dead_duck->check_out_screen(window) == true)
        is_dead = false;
}

sf::Color getcolor(const sf::Sprite *sprite, sf::Vector2f pos_mouse) {
    sf::Vector2f localPoint = sprite->getInverseTransform().transformPoint(pos_mouse.x, pos_mouse.y);
    const sf::Texture *texture = sprite->getTexture();
    sf::Image image = texture->copyToImage();

    if (localPoint.x < 0 || localPoint.y < 0 ||
        localPoint.x >= image.getSize().x || localPoint.y >= image.getSize().y) {
        return sf::Color::Transparent;
    }
    return image.getPixel((unsigned int)(localPoint.x), (unsigned int)(localPoint.y));
}

void Duck::check_shoot(sf::Vector2f pos_mouse)
{
    update_position();
    sf::Image *img_sprite;

    if ((Duck_sprite->getGlobalBounds().contains(pos_mouse) == true) && (getcolor(Duck_sprite, pos_mouse) != sf::Color::Transparent)) {
        is_dead = true;
        dead_duck->clock->restart();
        dead_duck->change_position(current_position, pos_mouse);
        change_dir();
        reset_pos();
        Duck_clock->restart();
    }
}

Duck::~Duck() {
    delete Duck_sprite;
    delete Duck_texture;
    delete Duck_clock;
}
