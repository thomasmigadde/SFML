#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <optional>
#include <memory>
#include <random>
#include <vector>
#include "ass.hpp"
using namespace sf;
using namespace std;




int main()
{
    try{
        sf::RenderWindow window(sf::VideoMode({800u, 600u}), "SFML Falling Emoji Game");
        std::vector<FallingObject> objects;
        sf::Texture cutie;
        
        //spawn timer
        sf::Clock SpawnTimer;
        const float SpawnInterval = 1.0f;
        
        window.setFramerateLimit(60);
        std::mt19937 gen(std::random_device{}());
        if(!cutie.loadFromFile("C:\\Users\\User\\Desktop\\SFML\\images1.jfif")) {
                std::cerr << "Failed to load cutie.png" << std::endl;
                return 1;
            }

    
        while (window.isOpen()) {

            if(SpawnTimer.getElapsedTime().asSeconds() > SpawnInterval)
            {
                FallingObject obj;
                obj.cute = std::make_unique<CircleShape>(30.f);
            // Sprite cutieSprite(cutie);
                obj.cute -> setTexture(&cutie);
                obj.spawn(gen);
                objects.push_back(std::move(obj));
                SpawnTimer.restart();
            }

            while (auto event = window.pollEvent()) {
                if (event->is<sf::Event::Closed>()) {
                    window.close();
                }
               
              }
            //clean _up
            for(int i = static_cast<int>(objects.size()) - 1; i >= 0; --i){
                if(objects[i].cute && objects[i].cute->getPosition().y > 600.f){
                    objects.erase(objects.begin() + i);
                }
            
            }  
            window.clear(sf::Color::Black);
            //window.clear(sf::Color::Black);
            for(auto& ob : objects){
                 if(ob.active){
                    ob.update();
                };
                }
            for(auto& obj : objects){
                obj.draw(window);
            }
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