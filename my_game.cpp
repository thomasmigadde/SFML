#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Emoji Game");

    sf::CircleShape sad(50.f);
    sf::CircleShape cute(50.f);
    sad.setPosition(375.f, 275.f);
    cute.setPosition(425.f, 325.f);

    sf::Texture sadTexture, cuteTexture;
    if (!sadTexture.loadFromFile("images (12).jfif")) {
        std::cerr << "Failed to load sad emoji" << std::endl;
    } else {
        sad.setTexture(&sadTexture);
    }
    if (!cuteTexture.loadFromFile("images (13).jfif")) {
        std::cerr << "Failed to load cute emoji" << std::endl;
    } else {
        cute.setTexture(&cuteTexture);
    }

    window.setFramerateLimit(60);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            cute.move(-5.f, 0.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            cute.move(5.f, 0.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            cute.move(0.f, -5.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            cute.move(0.f, 5.f);
        }

        window.clear(sf::Color::Black);
        window.draw(sad);
        window.draw(cute);
        window.display();
    }

    return 0;
}

