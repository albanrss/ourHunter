/*
** EPITECH PROJECT, 2024
** ourHunter
** File description:
** ducks
*/

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#ifndef DUCK_HPP_
    #define DUCK_HPP_

class Duck {
    public:
        sf::Texture *Duck_texture;
        sf::Sprite *Duck_sprite;
        sf::Vector2f current_position;
        Duck();
        ~Duck();
        void refresh_position(sf::Vector2f);
        void display_sprite(sf::RenderWindow &windows);
};

#endif