
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <optional>
#include <random>
#include "assNewwwww.hpp"

using namespace sf;



std::random_device rd;
std::mt19937 gen(rd());
std::uniform_real_distribution<float> disX(50.f, 750.f);
std::uniform_real_distribution<float> disY(50.f, 550.f);
std::uniform_int_distribution<int> disSpeed(1, 5);

sf::Font font;
sf::Text scoreText(font, "Score: 0", 24);

void init() {
    if(!font.openFromFile("C:\\Users\\User\\Desktop\\SFML\\fonts.ttf")){
        throw std::runtime_error("Failed to load font");
    }
    scoreText.setFillColor(Color::White);
    scoreText.setPosition({10.f, 10.f});
}

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
    
    init();
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
            scoreText.setString("Score: " + std::to_string(score));
            cute.setPosition({100.f, 100.f});
            sad.setPosition({disX(gen), disY(gen)});
            sad.move({disSpeed(gen), disSpeed(gen)});
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
        window.draw(scoreText);
        window.display();
    }
    return 0;
}
