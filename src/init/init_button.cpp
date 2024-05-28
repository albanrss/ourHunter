/*
** EPITECH PROJECT, 2024
** EPITECH
** File description:
** init_button
*/

#include "my.hpp"

button_t *init_button(void (*callback)(void), sf::Vector2f pos, sf::Vector2f size)
{
    button_t *button = new button_t;

    button->rect = new sf::RectangleShape(size);
    button->rect->setOrigin(size.x / 2, size.y / 2);
    button->rect->setPosition(pos);    
    button->sprite = NULL;
    button->text = NULL;
    button->callback = callback;
    return button;
}
