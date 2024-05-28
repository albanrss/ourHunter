/*
** EPITECH PROJECT, 2024
** struct
** File description:
** struct
*/

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#ifndef STRUCT_HPP_
    #define STRUCT_HPP_

typedef struct animated_s {
    sf::IntRect rect_sprite;
    int current_frame;
    int max_frame;
}animated_t;

typedef struct img_s {
    sf::Texture *texture;
    sf::Sprite *sprite;
    sf::Vector2f current_position;
    animated_t *animated;
}img_t;

typedef struct time2_s {
    sf::Clock *clock;
    float seconds;
}time2_t;


#endif /* !STRUCT_HPP_ */
