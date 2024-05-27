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
        bool is_dead;
        sf::Vector2f dir_vector;
        sf::Clock *Duck_clock;
        sf::Texture *Duck_texture;
        sf::Sprite *Duck_sprite;
        sf::Image *Duck_image;
        sf::Vector2f current_position;
        sf::IntRect rect_sprite;
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
        void display_sprite(sf::RenderWindow &windows);
        void start_another();
};

#endif