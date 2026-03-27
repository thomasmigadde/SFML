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
        // Event handling
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
            if (const auto* keyEvent = event->getIf<sf::Event::KeyPressed>()) {
                switch (keyEvent->code) {
                    case sf::Keyboard::Key::Escape:
                        window.close();
                        break;
                        
                    case sf::Keyboard::Key::Left:
                        cute.move(-10, 0);
                        break;
                        
                    case sf::Keyboard::Key::Right:
                        cute.move(10, 0);
                        break;
                        
                    case sf::Keyboard::Key::Up:
                        cute.move(0, -10);
                        break;
                        
                    case sf::Keyboard::Key::Down:
                        cute.move(0, 10);
                        break;
                        
                    default:
                        break;
                }
            }
        }

        // Rendering - CORRECT ORDER:
        window.clear(sf::Color::Black);   // Clear first
        window.draw(sad);                 // Draw sad emoji
        window.draw(cute);                // Draw cute emoji
        window.display();                 // Display last
    }

    return 0;
}