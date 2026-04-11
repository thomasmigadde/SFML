#include <SFML/Graphics.hpp>
using namespace sf;

int main() {
    RenderWindow window(VideoMode(800, 600), "SFML Syntax Example");
    window.setFramerateLimit(60);

    Texture texture;
    if (!texture.loadFromFile("cute_image.jpg")) {  // Using available image
        return -1;
    }
    Sprite sprite(texture);
    sprite.setPosition(100.f, 100.f);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        window.clear(Color::Black);
        window.draw(sprite);
        window.display();
    }

    return 0;
}

