/*
** EPITECH PROJECT, 2024
** EPITECH
** File description:
** init_text
*/

#include "my.hpp"

sf::Text *init_text(string str, sf::Vector2f pos, sf::Font font, int size, sf::Color color)
{
    sf::Text *text = new sf::Text;

    text->setString(str);
    text->setFont(font);
    text->setColor(color);
    text->setCharacterSize(size);
    text->setPosition(pos);
    return text;
}
