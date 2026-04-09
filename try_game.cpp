#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

int main() {
    RenderWindow window(VideoMode(800, 600), "Emoji Game");
    window.setFramerateLimit(60);

    // Create emojis
    CircleShape sad(50), cute(50);
    sad.setPosition(375, 275);
    cute.setPosition(100, 100);

    Texture sadt, cutet;
    if (!sadt.loadFromFile("images (12).jfif")) {
        std::cerr << "Failed to load sad emoji\n";
    }
    sad.setTexture(&sadt);

    if (!cutet.loadFromFile("images (13).jfif")) {
        std::cerr << "Failed to load cute emoji\n";
    }
    cute.setTexture(&cutet);

    int score = 0;

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        // Movement controls
        if (Keyboard::isKeyPressed(Keyboard::Left))  cute.move(-5, 0);
        if (Keyboard::isKeyPressed(Keyboard::Right)) cute.move(5, 0);
        if (Keyboard::isKeyPressed(Keyboard::Up))    cute.move(0, -5);
        if (Keyboard::isKeyPressed(Keyboard::Down))  cute.move(0, 5);

        // Collision check
        if (cute.getGlobalBounds().intersects(sad.getGlobalBounds())) {
            score++;
            std::cout << "Collision! Score: " << score << std::endl;
            // Reset cute position
            cute.setPosition(100, 100);
        }

        // Keep cute inside window
        Vector2f pos = cute.getPosition();
        if (pos.x < 0) cute.setPosition(0, pos.y);
        if (pos.y < 0) cute.setPosition(pos.x, 0);
        if (pos.x + cute.getRadius()*2 > 800) cute.setPosition(800 - cute.getRadius()*2, pos.y);
        if (pos.y + cute.getRadius()*2 > 600) cute.setPosition(pos.x, 600 - cute.getRadius()*2);

        // Render
        window.clear(Color::Black);
        window.draw(sad);
        window.draw(cute);
        window.display();
    }

    return 0;
}
