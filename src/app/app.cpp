/*
** EPITECH PROJECT, 2024
** cpp
** File description:
** test
*/

#include "my.hpp"

int start_app(class Duck *duck_entity)
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "My_test in cpp");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        duck_entity->display_sprite(window);
        window.display();
    }
    duck_entity->~Duck();
    return 0;
}
