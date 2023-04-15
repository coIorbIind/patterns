#pragma once

#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

using namespace sf;

class Proxy {
private:
    RenderWindow *window;
    Sprite *sprite;
    bool imageLoadFlag;
    bool moving;

    void changeImageLoadFlag() {
        this->imageLoadFlag = !this->imageLoadFlag;
    }

public:
    Proxy(RenderWindow *renderWindow, Sprite *sprite) {
        this->window = renderWindow;
        this->sprite = sprite;
        this->imageLoadFlag = false;
        this->moving = false;
    }

    ~Proxy() {
        delete this->sprite;
        delete this->window;
    }

    void changeMoving(bool canMove) {
        moving = canMove;
    }

    void renderBackground(Event *event) {
        if (event->mouseButton.button == Mouse::Right) {
            if (!this->imageLoadFlag){
                window->draw(*sprite);
                window->display();

            } else {
                window->clear(Color::White);
                window->display();
            }
            this->changeImageLoadFlag();
        } else if (this->imageLoadFlag) {
            this->changeMoving(true);
        }
    }

    void moveBackground() {
        if (this->moving) {
            Vector2i pixelPos = Mouse::getPosition(*window);
            Vector2f pos = window->mapPixelToCoords(pixelPos);

            float dX = pos.x - sprite->getPosition().x;
            float dY = pos.y - sprite->getPosition().y;

            sprite->move(dX, dY);
            window->clear(Color::White);
            window->draw(*sprite);
            window->display();
        }
    }
};
