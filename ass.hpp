#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <random>
using namespace sf;
using namespace std;
struct FallingObject
{
    //Sprite* sprite;
    //Sprite sprite;
    unique_ptr<CircleShape> cute;
    float speed;
    float x; 
    bool active;
   

// Constructor to initialize the object
    FallingObject() :cute(nullptr), speed(0.f), x(0.f), active(false) {}
   /* ~FallingObject() {
        delete sprite;
    }  
        */
//spawn function to set random position and speed
    void spawn(std::mt19937& gen) {
        std::uniform_real_distribution<float> disX(50.f, 750.f);
        std::uniform_int_distribution<int> disSpeed(1, 10);
        x = disX(gen);
        speed = disSpeed(gen);
        cute->setPosition(Vector2f(x, -50.f));
        //cute.setPosition(sf::Vector2(x, -cute.getGlobalBounds().position.y));
        active = true;
    }

    //update function to move the object downwards
    void update(){
        if(active){
            cute->move({0.f,speed});
            if(cute->getPosition().y > 600.f){
                active = false;
            }
        }
    }

//draw if active
    void draw(RenderWindow& window) {
        if (active) {
            window.draw(*cute);
        }
    }


};