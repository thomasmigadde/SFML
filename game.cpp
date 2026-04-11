#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

int main() {
    RenderWindow window(VideoMode(800, 600), "SFML Emoji Collision Game");
    window.setFramerateLimit(60);

    CircleShape sad(50.f), cute(50.f);
    sad.setPosition(375.f, 275.f);
    cute.setPosition(100.f, 100.f);

    Texture sadTexture, cuteTexture;
    if (!sadTexture.loadFromFile("images (12).jfif")) {
        std::cerr << "Sad emoji missing" << std::endl;
    } else {
        sad.setTexture(&amp;sadTexture);
    }
    if (!cuteTexture.loadFromFile("images (13).jfif")) {
        std::cerr << "Cute emoji missing" << std::endl;
    } else {
        cute.setTexture(&amp;cuteTexture);
    }

    int score = 0;

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        // Controls: WASD or Arrows
        if (Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::Left))  cute.move(-5.f, 0.f);
        if (Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Right)) cute.move(5.f, 0.f);
        if (Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Up))    cute.move(0.f, -5.f);
        if (Keyboard::isKeyPressed(Keyboard::S) || Keyboard::isKeyPressed(Keyboard::Down))  cute.move(0.f, 5.f);

        // Collision detection
        if (cute.getGlobalBounds().intersects(sad.getGlobalBounds())) {
            score++;
            std::cout << "Hit! Score: " << score << std::endl;
            cute.setPosition(100.f, 100.f);
            sad.setPosition(375.f + (rand() % 100 - 50), 275.f + (rand() % 100 - 50));  // Slight sad move
        }

        // Keep cute in bounds
        FloatRect cBounds = cute.getGlobalBounds();
        if (cBounds.left < 0) cute.setPosition(0.f, cBounds.top);
        if (cBounds.top < 0) cute.setPosition(cBounds.left, 0.f);
        if (cBounds.left + cBounds.width > 800.f) cute.setPosition(800.f - cBounds.width, cBounds.top);
        if (cBounds.top + cBounds.height > 600.f) cute.setPosition(cBounds.left, 600.f - cBounds.height);

        window.clear(Color::Black);
        window.draw(sad);
        window.draw(cute);
        window.display();
    }

    std::cout << "Final Score: " << score << std::endl;
    return 0;
}

