#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML Window");

    // Optional: create circle once outside the loop if it doesn't change
    CircleShape sad , cute;
    sad.setRadius(50);
    cute.setRadius(50);
    sad.setPosition({375, 275});
    cute.setPosition({425, 325});

    Texture sadt, cutet;
    
    if(!sadt.loadFromFile("images (12).jfif")) {  // Fixed: added space
        std::cerr << "Failed to load sad emoji" << std::endl;
    }
    sad.setTexture(&sadt);
    
    if (!cutet.loadFromFile("images (13).jfif")) {  // Fixed: added space
        std::cerr << "Failed to load cute emoji" << std::endl;
    }
    cute.setTexture(&cutet);  // Fixed: removed duplicate sad.setTexture line
    
    // Set framerate limit for smoother movement
    window.setFramerateLimit(60);

    while (window.isOpen()) {
    sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Continuous input handling
        if (Keyboard::isKeyPressed(Keyboard::Left))  cute.move({-5.f, 0.f});
        if (Keyboard::isKeyPressed(Keyboard::Right)) cute.move({5.f, 0.f});
        if (Keyboard::isKeyPressed(Keyboard::Up))    cute.move({0.f, -5.f});
        if (Keyboard::isKeyPressed(Keyboard::Down))  cute.move({0.f, 5.f});

        // Rendering
        window.clear(sf::Color::Black);
        window.draw(sad);
        window.draw(cute);
        window.display();
    }
 return 0;
}