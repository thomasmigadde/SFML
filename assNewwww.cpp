#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <optional>
#include <memory>
#include <random>
#include "ass.hpp"
using namespace sf;
using namespace std;




int main()
{
    try{
        sf::RenderWindow window(sf::VideoMode({800u, 600u}), "SFML Falling Emoji Game");
        FallingObject obj;
        sf::Texture cutie;
        
        
        if(!cutie.loadFromFile("C:\\Users\\User\\Desktop\\SFML\\images1.jfif")) {
            std::cerr << "Failed to load cutie.png" << std::endl;
            return 1;
        }
        obj.cute = std::make_unique<CircleShape>(30.f);
       // Sprite cutieSprite(cutie);
        obj.cute -> setTexture(&cutie);
        window.setFramerateLimit(60);
        std::mt19937 gen(std::random_device{}());
        obj.spawn(gen);



        while (window.isOpen()) {
            while (auto event = window.pollEvent()) {
                if (event->is<sf::Event::Closed>()) {
                    window.close();
                }
               
              }
              
            window.clear(sf::Color::Black);
            if(!obj.active){
                obj.spawn(gen);
            }
            //window.clear(sf::Color::Black);
            obj.update();
            obj.draw(window);
            window.display();
        }
    } 
    catch (const std::exception& e) { 
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Unknown exception occurred." << std::endl;
    }
  return 0;       
}