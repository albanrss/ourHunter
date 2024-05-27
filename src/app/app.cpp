/*
** EPITECH PROJECT, 2024
** cpp
** File description:
** test
*/

#include "my.hpp"

int start_app(class Duck *duck)
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "OurDuckHunter");

    while (window.isOpen()) {
        analyze_events(duck, window);
        window.clear();
        (duck)->check_out_screen(window);
        (duck)->move_sprite();
        (duck)->display_sprite(&window);
        window.display();
    }
    duck->~Duck();
    return 0;
}
