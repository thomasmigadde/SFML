#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <optional>
#include <random>
using namespace sf;
using namespace std;


struct FallingObject
{
    Sprite* sprite;
    //Sprite sprite;
    unique_ptr<Sprite> spritePtr;
    float speed;
    float x; 
    bool active;
   

// Constructor to initialize the object
    FallingObject() :sprite(nullptr), speed(0.f), x(0.f), active(false) {}
    ~FallingObject() {
        delete sprite;
    }  
//spawn function to set random position and speed
    void spawn(std::mt19937& gen) {
        std::uniform_real_distribution<float> disX(50.f, 750.f);
        std::uniform_int_distribution<int> disSpeed(1, 5);
        x = disX(gen);
        speed = disSpeed(gen);
        sprite->setPosition(Vector2f(x, -sprite->getGlobalBounds().position.y));
        //sprite.setPosition(sf::Vector2(x, -sprite.getGlobalBounds().position.y));
        active = true;
    }

    //update function to move the object downwards
    void update(){
        if(active){
            sprite->move({0.f,speed});
            if(sprite->getPosition().y > 600.f){
                active = false;
            }
        }
    }

//draw if active
    void draw(RenderWindow& window) {
        if (active) {
            window.draw(*sprite);
        }
    }


};

int main()
{
        sf::RenderWindow window(sf::VideoMode({800u, 600u}), "SFML Emoji Game");
        FallingObject obj;
        sf::Texture cutie;
        
        
        if(!cutie.loadFromFile("C:\\Users\\User\\Desktop\\SFML\\images1.jfif")) {
            std::cerr << "Failed to load cutie.png" << std::endl;
            return 1;
        }
        obj.sprite = new Sprite(cutie);
       // Sprite cutieSprite(cutie);
        //obj.sprite -> setTexture(cutie);
        window.setFramerateLimit(60);
        std::mt19937 gen(std::random_device{}());
        obj.spawn(gen);



        while (window.isOpen()) {
            while (auto event = window.pollEvent()) {
                if (event->is<sf::Event::Closed>()) {
                    window.close();
                }
               
                window.clear(sf::Color::Black);
                if(!obj.active){
                    obj.spawn(gen);
                }
                obj.update();
                obj.draw(window);
                window.display();
                
    
            }
        }
  return 0;       
}