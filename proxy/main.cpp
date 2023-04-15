#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "Proxy.h"

using namespace sf;

int main() {
    Image background;
    if (!background.loadFromFile(R"(D:\University\third_year\patterns\proxy\data\lake.jpg)"))
        return -1;

    RenderWindow window(VideoMode(background.getSize().x, background.getSize().y), "ImageController");

    Texture texture;
    texture.loadFromImage(background);

    Sprite sprite;
    sprite.setTexture(texture);
    sprite.setPosition(0, 0);
    Event event;
    Proxy *proxy = new Proxy(&window, &sprite);
    window.setFramerateLimit(60);
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == Event::MouseButtonPressed) {
                proxy->renderBackground(&event);
            }
            if (event.type == Event::MouseButtonReleased) {
                proxy->changeMoving(false);
            }
            if (event.type == Event::MouseMoved) {
                proxy->moveBackground();
            }
            if (event.type == Event::Closed)
                window.close();
        }
    }

    return 0;
}
