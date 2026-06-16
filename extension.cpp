#include <C:\Users\User\Desktop\SFML\newwww.cpp>
#include <C:\Users\User\Desktop\SFML\assNewwww.cpp>

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
