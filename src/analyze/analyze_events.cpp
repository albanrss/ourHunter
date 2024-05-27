/*
** EPITECH PROJECT, 2024
** analyze events
** File description:
** analyze_events
*/

#include "my.hpp"

void analyze_events(class Duck *duck, sf::RenderWindow &window)
{
    sf::Event event;

    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::MouseButtonReleased &&
            event.mouseButton.button == sf::Mouse::Button::Left)
            (duck)->check_shoot(sf::Vector2f(event.mouseButton.x,
            event.mouseButton.y));
    }
}