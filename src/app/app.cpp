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
        compute_game(duck, window);
        window.display();
    }
    delete_game(duck);
    return 0;
}
