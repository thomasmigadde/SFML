#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

int main() {
    RenderWindow window(VideoMode(800, 600), "Try Game - Emoji Collision");
    window.setFramerateLimit(60);

    CircleShape sad(50), cute(50);
    sad.setPosition(375, 275);
    cute.setPosition(100, 100);

    Texture sadt, cutet;
    if (!sadt.loadFromFile("images (12).jfif")) {
        std::cerr << "Failed to load sad emoji" << std::endl;
    } else {
        sad.setTexture(&amp;sadt);
    }
    if (!cutet.loadFromFile("images (13).jfif")) {
        std::cerr << "Failed to load cute emoji" << std::endl;
    } else {
        cute.setTexture(&amp;cutet);
    }

    int score = 0;

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        // Arrow keys and WASD
        if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A)) cute.move(-5, 0);
        if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)) cute.move(5, 0);
        if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W)) cute.move(0, -5);
        if (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S)) cute.move(0, 5);

        // Collision
        if (cute.getGlobalBounds().intersects(sad.getGlobalBounds())) {
            score++;
            std::cout << "Collision! Score: " << score << std::endl;
            cute.setPosition(100, 100);
        }

        // Bounds check
        FloatRect pos = cute.getGlobalBounds();
        if (pos.left < 0) cute.setPosition(0, pos.top);
        if (pos.top < 0) cute.setPosition(pos.left, 0);
        if (pos.left + pos.width > 800) cute.setPosition(800 - pos.width, pos.top);
        if (pos.top + pos.height > 600) cute.setPosition(pos.left, 600 - pos.height);

        window.clear(Color::Black);
        window.draw(sad);
        window.draw(cute);
        window.display();
    }

    return 0;
}

