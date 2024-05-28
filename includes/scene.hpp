/*
** EPITECH PROJECT, 2024
** EPITECH
** File description:
** scene
*/

#ifndef SCENE_H
#define SCENE_H

typedef struct button_s {
    sf::Sprite sprite;
    sf::Vector2f position;
    sf::RectangleShape rect;
    sf::Text text;
    bool is_hover;
    bool is_click;
    void (*callback)(void);
} button_t;

typedef struct contents_s {
    sf::Sprite bg;
    sf::Sprite container;
    sf::Sprite infos_containers[];
    sf::Text infos_texts[];
    button_t buttons[];
} contents_t;


class Scene {
    public:
        contents_t *contents;
        
        Scene(contents_t *contents);
        ~Scene();

        void draw(sf::RenderWindow *window);
        void events(sf::RenderWindow *window);
};


#endif //SCENE_H
