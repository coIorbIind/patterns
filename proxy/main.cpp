#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "RealImage.h"
#include "ProxyImage.h"

using namespace sf;

int main() {
    Image background;
    if (!background.loadFromFile(R"(D:\University\third_year\patterns\proxy\data\lake.jpg)"))
        return -1;

    RenderWindow window(VideoMode(background.getSize().x + 300, background.getSize().y + 200), "ImageController");

    Texture texture;
    texture.loadFromImage(background);

    Event event;

    RectangleShape rectangle(sf::Vector2f((float)background.getSize().x, (float)background.getSize().y));
    rectangle.setPosition(10, 10);
    window.draw(rectangle);
    window.display();

    RealImage *image = new RealImage(&window, &texture, &rectangle);
    ProxyImage *proxy = new ProxyImage(image);
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
