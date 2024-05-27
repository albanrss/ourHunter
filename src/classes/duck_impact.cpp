/*
** EPITECH PROJECT, 2024
** ourHunter
** File description:
** duck_impact
*/

#include "my.hpp"

DuckImpact::DuckImpact(void)
{
    impact_sprite = new sf::Sprite;
    impact_texture = new sf::Texture;
    dead_sprite = new sf::Sprite;
    dead_texture = new sf::Texture;
    clock_time = new time2_t;
    clock_time->seconds = 0;
    clock_time->clock = new sf::Clock;
    impact_texture->loadFromFile("assets/impact.png");
    impact_sprite->setTexture(*impact_texture);
    impact_sprite->setOrigin(sf::Vector2f((11.0 / 2), (11.0 / 2)));
    impact_sprite->setPosition(sf::Vector2f(-11.0, -11.0));
    dead_texture->loadFromFile("assets/duck_dead.png");
    dead_sprite->setTexture(*dead_texture);
    dead_sprite->setOrigin(sf::Vector2f(55, 55));
    dead_sprite->setPosition(sf::Vector2f(-110.0, -110.0));
    death_vector = sf::Vector2f(sqrt(3 / 2), 0.5);
}

void DuckImpact::change_position(sf::Vector2f pos, sf::Vector2f pos_mouse)
{
    impact_sprite->setPosition(pos_mouse);
    dead_sprite->setPosition(pos);
}

void DuckImpact::move_sprite(void)
{
    update_clock();

    dead_sprite->move(mult3(death_vector, clock_time->seconds * 0.2));
    impact_sprite->move(mult3(death_vector, clock_time->seconds * 0.2));
}

void DuckImpact::update_clock(void)
{
    clock_time->seconds = clock_time->clock->getElapsedTime().asMilliseconds();
    clock_time->clock->restart();
}

void DuckImpact::display_sprites(sf::RenderWindow &window)
{
    window.draw(*dead_sprite);
    window.draw(*impact_sprite);
}

void DuckImpact::reset_pos(void)
{
    impact_sprite->setPosition(sf::Vector2f{-11, -11});
    dead_sprite->setPosition(sf::Vector2f{-110, -110});
}

bool DuckImpact::check_out_screen(sf::RenderWindow &window)
{
    sf::Vector2u size_window = window.getSize();
    sf::Vector2f pos_sprite = dead_sprite->getPosition();
    sf::FloatRect rect_window = sf::FloatRect(sf::Vector2f{0, 0},
        sf::Vector2f{(float)size_window.x, (float)size_window.y});

    if (sf::FloatRect(dead_sprite->getGlobalBounds()).intersects(rect_window)
        == false) {
        reset_pos();
        return true;
    }
    return false;
}
DuckImpact::~DuckImpact()
{
    delete impact_sprite;
    delete impact_texture;
    delete dead_sprite;
    delete dead_texture;
}

