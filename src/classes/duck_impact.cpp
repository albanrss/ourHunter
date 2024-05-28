/*
** EPITECH PROJECT, 2024
** ourHunter
** File description:
** duck_impact
*/

#include "my.hpp"

DuckImpact::DuckImpact(void)
{
    DeadSprite = init_img("assets/duck_dead.png", sf::Vector2f(-110.0, -110.0),
        sf::Vector2f(110, 110));
    ImpactSprite = init_img("assets/impact.png", sf::Vector2f(-11, -11),
        sf::Vector2f(11, 11));
    clock_time = init_time();
    death_vector = sf::Vector2f(sqrt(3 / 2), 0.5);
}

void DuckImpact::change_position(sf::Vector2f pos, sf::Vector2f pos_mouse)
{
    ImpactSprite->sprite->setPosition(pos_mouse);
    DeadSprite->sprite->setPosition(pos);
}

void DuckImpact::move_sprite(void)
{
    update_clock();

    DeadSprite->sprite->move(mult3(death_vector, clock_time->seconds * 0.2));
    ImpactSprite->sprite->move(mult3(death_vector, clock_time->seconds * 0.2));
}

void DuckImpact::update_clock(void)
{
    clock_time->seconds = clock_time->clock->getElapsedTime().asMilliseconds();
    clock_time->clock->restart();
}

void DuckImpact::display_sprites(sf::RenderWindow &window)
{
    window.draw(*DeadSprite->sprite);
    window.draw(*ImpactSprite->sprite);
}

void DuckImpact::reset_pos(void)
{
    ImpactSprite->sprite->setPosition(sf::Vector2f{-11, -11});
    DeadSprite->sprite->setPosition(sf::Vector2f{-110, -110});
}

bool DuckImpact::check_out_screen(sf::RenderWindow &window)
{
    sf::Vector2u size_window = window.getSize();
    sf::Vector2f pos_sprite = DeadSprite->sprite->getPosition();
    sf::FloatRect rect_window = sf::FloatRect(sf::Vector2f{0, 0},
        sf::Vector2f{(float)size_window.x, (float)size_window.y});

    if (sf::FloatRect(DeadSprite->sprite->getGlobalBounds()).intersects(rect_window)
        == false) {
        reset_pos();
        return true;
    }
    return false;
}
DuckImpact::~DuckImpact()
{
    delete_img(ImpactSprite);
    delete_img(DeadSprite);
    delete_time(clock_time);
}

