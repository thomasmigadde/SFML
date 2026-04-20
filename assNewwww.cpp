#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <optional>
#include <random>
using namespace sf;
using namespace std;


struct FallingObject
{
    Sprite sprite;
    float speed;
    float x; 
    bool active;
   

// Constructor to initialize the object
    FallingObject() : speed(0.f), x(0.f), active(false) {}

//spawn function to set random position and speed
    void spawn(std::mt19937& gen) {
        std::uniform_real_distribution<float> disX(50.f, 750.f);
        std::uniform_int_distribution<int> disSpeed(1, 5);
        x = disX(gen);
        speed = disSpeed(gen);
        sprite.setPosition(sf::Vector2(x, -sprite.getGlobalBounds().position.y));
        active = true;
    }

    //update function to move the object downwards
    void update(){
        if(active){
            sprite.move({0.f,speed});
            if(sprite.getPosition().y > 600.f){
                active = false;
            }
        }
    }

//draw if active
    void draw(RenderWindow& window) {
        if (active) {
            window.draw(sprite);
        }
    }


};