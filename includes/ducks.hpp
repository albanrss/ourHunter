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
        float elapsed_time;
        float flappy_time;
        float angle;
        float random_dir;
        double speed;
        sf::Vector2f dir_vector;
        sf::Clock *Duck_clock;
        sf::Texture *Duck_texture;
        sf::Sprite *Duck_sprite;
        sf::Vector2f current_position;
        sf::IntRect rect_sprite;
        Duck();
        ~Duck();
        void update_position();
        void update_clock();
        void change_dir();
        void move_sprite();
        void animate_sprite();
        void display_sprite(sf::RenderWindow &windows);
};

#endif