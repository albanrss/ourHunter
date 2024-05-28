/*
** EPITECH PROJECT, 2024
** ourHunter
** File description:
** ducks
*/

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "struct.hpp"

#ifndef DUCK_HPP_
    #define DUCK_HPP_

class Duck {
    public:
        time2_t *clock_time;
        float flappy_time;
        float angle;
        float random_dir;
        double speed;
        bool is_dead;
        img_t *DuckSprite;
        sf::Vector2f dir_vector;
        class DuckImpact *dead_duck;
        Duck();
        ~Duck();
        void update_position();
        void update_clock();
        void change_dir();
        void move_sprite();
        void reset_pos();
        void animate_sprite();
        void check_out_screen(sf::RenderWindow &windows);
        void check_shoot(sf::Vector2f pos_mouse);
        void display_sprite(sf::RenderWindow *windows);
};

#endif