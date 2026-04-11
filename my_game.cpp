#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(800u, 600u), "SFML Emoji Game");

    sf::CircleShape sad(50.f);
    sf::CircleShape cute(50.f);
    sad.setPosition(375.f, 275.f);
    cute.setPosition(100.f, 100.f);

    sf::Texture sadTexture, cuteTexture;
    if (!sadTexture.loadFromFile("images (12).jfif")) {
        std::cerr << "Failed to load sad emoji" << std::endl;
    } else {
        sad.setTexture(&amp;sadTexture);
    }
    if (!cuteTexture.loadFromFile("images (13).jfif")) {
        std::cerr << "Failed to load cute emoji" << std::endl;
    } else {
        cute.setTexture(&amp;cuteTexture);
    }

    window.setFramerateLimit(60);

    int score = 0;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // WASD movement
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

        // Collision
        if (cute.getGlobalBounds().intersects(sad.getGlobalBounds())) {
            score++;
            std::cout << "Score: " << score << std::endl;
            cute.setPosition(100.f, 100.f);
        }

        // Bounds
        sf::FloatRect bounds = cute.getGlobalBounds();
        if (bounds.left < 0) cute.setPosition(0.f, bounds.top);
        if (bounds.top < 0) cute.setPosition(bounds.left, 0.f);
        if (bounds.left + bounds.width > 800) cute.setPosition(800 - bounds.width, bounds.top);
        if (bounds.top + bounds.height > 600) cute.setPosition(bounds.left, 600 - bounds.height);

        window.clear(sf::Color::Black);
        window.draw(sad);
        window.draw(cute);
        window.display();
    }

    return 0;
}

