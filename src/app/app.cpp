/*
** EPITECH PROJECT, 2024
** cpp
** File description:
** test
*/

#include "my.hpp"

int start_app(class Duck *duck_entity)
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "OurDuckHunter");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonReleased &&
                event.mouseButton.button == sf::Mouse::Button::Left)
                duck_entity->check_shoot(sf::Vector2f(event.mouseButton.x,
                    event.mouseButton.y));
        }
        window.clear();
        duck_entity->check_out_screen(window);
        duck_entity->move_sprite();
        duck_entity->display_sprite(window);
        window.display();
    }
    duck_entity->~Duck();
    return 0;
}
