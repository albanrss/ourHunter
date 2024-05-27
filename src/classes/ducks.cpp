/*
** EPITECH PROJECT, 2024
** duck.cpp
** File description:
** ducks
*/

#include "my.hpp"
#include <iostream>

Duck::Duck(void)
{
    is_dead = false;
    dead_duck = new DuckImpact;
    clock_time = init_time();
    DuckSprite = init_duck();
    flappy_time = 200;
    speed = 0.1;
    random_dir = (rand() % 3 + 1) * 1000;
    change_dir();
}

void Duck::change_dir(void)
{
    update_position();
    int x = rand() % 1865 + 55 + DuckSprite->current_position.x;
    int y = rand() % 1026 + 55;

    speed = double(rand() % 5 + 1) / 10;
    update_position();
    angle = atan2(y - DuckSprite->current_position.y,
        x - DuckSprite->current_position.x);
    dir_vector = sf::Vector2f({(float) cos(angle), (float) sin(angle)});
}

void Duck::update_position(void)
{
    DuckSprite->current_position =  DuckSprite->sprite->getPosition();
}

void Duck::update_clock(void)
{
    clock_time->seconds = clock_time->clock->getElapsedTime().asMilliseconds();
    clock_time->clock->restart();
}

void Duck::display_sprite(sf::RenderWindow *window)
{
    if (is_dead)
        dead_duck->display_sprites(*window);
    window->draw(*(DuckSprite->sprite));
}

void Duck::animate_sprite(void)
{
    flappy_time -= clock_time->seconds;

    if (flappy_time <= 0) {
        flappy_time = 200;
        if (DuckSprite->rect_sprite.left == 220)
            DuckSprite->rect_sprite.left = 0;
        else
            DuckSprite->rect_sprite.left += 110;
    }
    DuckSprite->sprite->setTextureRect(DuckSprite->rect_sprite);
}

void Duck::move_sprite(void)
{
    update_clock();
    update_position();

    animate_sprite();
    random_dir -= clock_time->seconds;
    if (random_dir <= 0) {
        random_dir = (double)(rand() % 3 + 1) * 1000;
        change_dir();
    }
    (DuckSprite->sprite)->move(mult3(dir_vector, clock_time->seconds * speed));
    update_position();
    if (is_dead)
        dead_duck->move_sprite();
}

void Duck::reset_pos(void)
{
    sf::Vector2f pos = sf::Vector2f(0, (float)(rand() % 700));

    change_dir();
    DuckSprite->sprite->setPosition(pos);
}

void Duck::check_out_screen(sf::RenderWindow &window)
{
    sf::Vector2u size_window = window.getSize();
    sf::Vector2f pos_sprite = DuckSprite->sprite->getPosition();
    sf::FloatRect rect_window = sf::FloatRect(sf::Vector2f{0, 0},
        sf::Vector2f{(float)size_window.x, (float)size_window.y});
    sf::FloatRect rect_sprite = DuckSprite->sprite->getGlobalBounds();

    if (rect_sprite.intersects(rect_window) == false)
        reset_pos();
    if (is_dead && dead_duck->check_out_screen(window) == true)
        is_dead = false;
}

sf::Color getcolor(const sf::Sprite *sprite, sf::Vector2f pos_mouse) {
    sf::Vector2f localPoint = sprite->getInverseTransform().transformPoint(
        pos_mouse.x, pos_mouse.y);
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

    if ((DuckSprite->sprite->getGlobalBounds().contains(pos_mouse) == true) &&
        (getcolor(DuckSprite->sprite, pos_mouse) != sf::Color::Transparent)) {
        is_dead = true;
        dead_duck->clock_time->clock->restart();
        dead_duck->change_position(DuckSprite->current_position, pos_mouse);
        change_dir();
        reset_pos();
        clock_time->clock->restart();
    }
}

Duck::~Duck() {
    delete_img(DuckSprite);
    delete_time(clock_time);
}
