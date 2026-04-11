#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
using namespace sf;

int main() {
    RenderWindow window(VideoMode(800, 600), "SFML Main Template");
    window.setFramerateLimit(60);

    Texture texture;
    if (!texture.loadFromFile("cute_image.jpg")) {
        std::cerr << "Failed to load cute_image.jpg" << std::endl;
        return -1;
    }
    Sprite sprite(texture);
    sprite.setPosition(100.f, 100.f);

    Font font;
    if (!font.loadFromFile("arial.ttf")) {  // Assume font available or skip
        std::cerr << "Failed to load arial.ttf" << std::endl;
    }
    Text text("Hello SFML!", font, 50);
    text.setPosition(300.f, 250.f);
    text.setFillColor(Color::White);

    Music music;
    if (!music.openFromFile("nice_music.ogg")) {
        std::cerr << "Failed to load nice_music.ogg" << std::endl;
    } else {
        music.play();
    }

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        window.clear(Color::Black);
        window.draw(sprite);
        window.draw(text);
        window.display();
    }
    return 0;
}

