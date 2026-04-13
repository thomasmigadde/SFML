
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <optional>

using namespace sf;

int main() {
    RenderWindow window(VideoMode({800u, 600u}), "SFML Emoji Game");

    CircleShape sad(50.f);
    sad.setPosition({375.f, 275.f});

    CircleShape cute(50.f);
    cute.setPosition({100.f, 100.f});

    sf::Texture cutie, sadie;
    if(!cutie.loadFromFile("C:\\Users\\User\\Desktop\\SFML\\images1.jfif")) {
        std::cerr << "Failed to load cutie.png" << std::endl;
        return 1;
    }
   
    if(!sadie.loadFromFile("C:\\Users\\User\\Desktop\\SFML\\images.jfif")) {
        std::cerr << "Failed to load sadie.png" << std::endl;
        return 1;
    }
    cute.setTexture(&cutie);
    sad.setTexture(&sadie);

    sf::Sprite cutieSprite(cutie);
    sf::Sprite sadieSprite(sadie);

    window.setFramerateLimit(60);

    int score = 0;

    while (window.isOpen()) {
        std::optional<Event> eventOpt;
        while ((eventOpt = window.pollEvent())) {
            if (eventOpt->is<Event::Closed>()) {
                window.close();
            }
        }

        if (Keyboard::isKeyPressed(Keyboard::Key::A)) {
            cute.move({-5.f, 0.f});
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::D)) {
            cute.move({5.f, 0.f});
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::W)) {
            cute.move({0.f, -5.f});
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::S)) {
            cute.move({0.f, 5.f});
        }

        if (cute.getGlobalBounds().findIntersection(sad.getGlobalBounds()).has_value()) {
            score++;
            std::cout << "Score: " << score << std::endl;
            cute.setPosition({100.f, 100.f});
            sad.setPosition({static_cast<float>(rand() % 700 + 50), static_cast<float>(rand() % 500 + 50)});
        }

        Vector2f pos = cute.getPosition();
        Rect<float> bounds = cute.getGlobalBounds();
        if (pos.x < 0.f) cute.setPosition({0.f, pos.y});
        if (pos.y < 0.f) cute.setPosition({pos.x, 0.f});
        if (pos.x + bounds.size.x > 800.f) cute.setPosition({800.f - bounds.size.x, pos.y});
        if (pos.y + bounds.size.y > 600.f) cute.setPosition({pos.x, 600.f - bounds.size.y});

        window.clear(Color::Black);
        window.draw(sad);
        window.draw(cute);
        window.display();
    }
    return 0;
}
