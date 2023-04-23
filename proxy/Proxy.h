//#pragma once
//
//#include <SFML/Graphics/Image.hpp>
//#include <SFML/Graphics/RenderWindow.hpp>
//#include <SFML/Window.hpp>
//#include <SFML/Graphics/Texture.hpp>
//#include <SFML/Graphics/Sprite.hpp>
//
//using namespace sf;
//
//class Proxy {
//private:
//    RenderWindow *window;
//    Texture *texture;
//    RectangleShape *rectangle;
//    bool imageLoadFlag;
//    bool moving;
//
//    void changeImageLoadFlag() {
//        this->imageLoadFlag = !this->imageLoadFlag;
//    }
//
//public:
//    Proxy(RenderWindow *renderWindow, Texture *texture, RectangleShape *rectangleShape) {
//        this->rectangle = rectangleShape;
//        this->window = renderWindow;
//        this->texture = texture;
//        this->imageLoadFlag = false;
//        this->moving = false;
//    }
//
//    ~Proxy() {
//        delete this->texture;
//        delete this->window;
//    }
//
//    void changeMoving(bool canMove) {
//        moving = canMove;
//    }
//
//    void renderBackground(Event *event) {
//        if (event->mouseButton.button == Mouse::Right) {
//            if (!this->imageLoadFlag){
//                rectangle->setTexture(texture);
//                window->draw(*rectangle);
//                window->display();
//            } else {
//                rectangle->setTexture(NULL);
//                window->draw(*rectangle);
//                window->display();
//            }
//            this->changeImageLoadFlag();
//        } else {
//            this->changeMoving(true);
//        }
//    }
//
//    void moveBackground() {
//        if (this->moving) {
//            Vector2i pixelPos = Mouse::getPosition(*window);
//            Vector2f pos = window->mapPixelToCoords(pixelPos);
//
//            float dX = pos.x - rectangle->getPosition().x;
//            float dY = pos.y - rectangle->getPosition().y;
//
//            rectangle->move(dX, dY);
//            window->clear();
//            window->draw(*rectangle);
//            window->display();
//        }
//    }
//};
