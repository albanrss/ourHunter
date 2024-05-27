/*
** EPITECH PROJECT, 2024
** cpp
** File description:
** test
*/

#include "my.hpp"

int start_app(game_t *data)
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "My_test in cpp");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(data->main_menu->sprite_main_menu);
        window.display();
    }
    return 0;
}
