#include <SFML/Graphics.hpp>
using namespace sf;

int main() {
    RenderWindow window(VideoMode(800, 600), "SFML 3.0 Window");

    Texture texture;
    if (!texture.loadFromFile("image.png")) {
        return -1; // fail if image not found
    }

    Sprite sprite(texture);
    sprite.setPosition(100, 100);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(sprite); // draw something!
        window.display();
    }
}

/*
sf::Texture texture;
texture.loadFromFile("image.png");

sf::Sprite sprite(texture);
sprite.setPosition(100, 100);

window.clear();
window.draw(sprite);
window.display();

sf::Texture texture;
texture.loadFromFile("image.png");

sf::Sprite sprite(texture);
sprite.setPosition(100, 100);

window.clear();
window.draw(sprite);
window.display();


sf::TcpSocket socket;
socket.connect("127.0.0.1", 53000);
*/