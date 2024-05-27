/*
** EPITECH PROJECT, 2024
** duckimpact
** File description:
** duckimpact
*/

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#ifndef DUCKIMPACT_HPP_
    #define DUCKIMPACT_HPP_

class DuckImpact {
    public:
        sf::Texture *impact_texture;
        sf::Sprite *impact_sprite;
        sf::Vector2f current_position;
        sf::Texture *dead_texture;
        sf::Sprite *dead_sprite;
        sf::Clock *clock;
        float elapsed_time;
        sf::Vector2f current_position_impact;
        sf::Vector2f current_position_dead;
        sf::Vector2f death_vector;
        DuckImpact();
        void display_sprites(sf::RenderWindow &windows);
        void change_position(sf::Vector2f pos, sf::Vector2f pos_mouse);
        void move_sprite();
        void update_clock();
        bool check_out_screen(sf::RenderWindow &windows);
        void reset_pos();
        ~DuckImpact();
};

#endif /* !DUCKIMPACT_HPP_ */
