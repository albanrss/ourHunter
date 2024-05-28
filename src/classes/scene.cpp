//
// Created by alban on 27/05/24.
//

#include "scene.h"
#include "my.hpp"

Scene::Scene(contents_t *contents)
{
    this->contents = contents;
}

Scene::~Scene()
{
    delete this->contents.bg;
    delete this->contents.container;
    delete this->contents.infos;
    for (int i = 0; i < sizeof(this->contents.infos_texts); i++) {
        delete this->contents.infos_texts[i];
    }
    for (int i = 0; i < sizeof(this->contents.infos_containers); i++) {
        delete this->contents.infos_containers[i];
    }
    for (int i = 0; i < sizeof(this->contents.buttons); i++) {
        delete this->contents.buttons[i]->sprite;
        delete this->contents.buttons[i]->text;
        delete this->contents.buttons[i]->font;
        delete this->contents.buttons[i];
    }
}

void Scene::draw(sf::RenderWindow *window)
{
    sf::draw(this->contents.bg);
    sf::draw(this->contents.container);
    for (int i = 0; i < sizeof(this->contents.infos_texts); i++) {
        sf::draw(this->contents.infos_texts[i]);
    }
    for (int i = 0; i < sizeof(this->contents.infos_containers); i++) {
        sf::draw(this->contents.infos_containers[i]);
    }
    for (int i = 0; i < sizeof(this->contents.buttons); i++) {
        sf::draw(this->contents.buttons[i]->sprite);
        sf::draw(this->contents.buttons[i]->text);
    }
}

void Scene::events(sf::RenderWindow *window)
{
    sf::Event event;
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window->close();
        if (event.type == sf::Event::MouseButtonPressed) {
            for (int i = 0; i < sizeof(this->contents.buttons); i++) {
                if (this->contents.buttons[i]->rect.contains(sf::Mouse::getPosition(*window))) {
                    this->contents.buttons[i]->is_click = true;
                    this->contents.buttons[i]->callback();
                }
            }
        }
    }
}
