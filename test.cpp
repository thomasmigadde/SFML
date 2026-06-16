    // ... [Your initialization code above this] ...
    int score = 0;
    int failure = 0;
    bool gameOver = false; // <--- ADD THIS FLAG

    while (window.isOpen()) {
        // 1. Handle Window Events (Always runs so the user can still close the window)
        std::optional<Event> eventOpt;
        while ((eventOpt = window.pollEvent())) {
            if (eventOpt->is<Event::Closed>()) {
                window.close();
            }
        }

        // 2. GAME LOGIC (Only runs if the game is NOT over)
        if (!gameOver) {
            // Spawn timer
            if(SpawnTimer.getElapsedTime().asSeconds() > SpawnInterval) {
                FallingObject obj;
                obj.cute = std::make_unique<CircleShape>(30.f);
                obj.cute->setTexture(&cutie);
                obj.spawn(gen);
                objects.push_back(std::move(obj));
                SpawnTimer.restart();
            }

            // Check for objects falling off screen
            for(int i = static_cast<int>(objects.size()) - 1; i >= 0; --i){
                if(objects[i].cute && objects[i].cute->getPosition().y > 600.f){
                    failure++;
                    failureText.setString("Failure: " + std::to_string(failure));
                    objects.erase(objects.begin() + i);
                }
            }  

            // Controls
            if (Keyboard::isKeyPressed(Keyboard::Key::A)) cute.move({-5.f, 0.f});
            if (Keyboard::isKeyPressed(Keyboard::Key::D)) cute.move({5.f, 0.f});
            if (Keyboard::isKeyPressed(Keyboard::Key::W)) cute.move({0.f, -5.f});
            if (Keyboard::isKeyPressed(Keyboard::Key::S)) cute.move({0.f, 5.f});

            // Collision detection
            for(auto& ob : objects) {
                if(ob.active) {
                    if (cute.getGlobalBounds().findIntersection(ob.cute->getGlobalBounds()).has_value()) {
                        score++;
                        scoreText.setString("Score: " + std::to_string(score));
                        cute.setPosition({100.f, 100.f});
                        ob.cute->setPosition({disX(gen), disY(gen)});
                        ob.cute->move({static_cast<float>(disSpeed(gen)), static_cast<float>(disSpeed(gen))});
                        ob.active = false;
                    }
                }
            }
           
            // Bounds checking for the player
            Vector2f pos = cute.getPosition();
            Rect<float> bounds = cute.getGlobalBounds();
            if (pos.x < 0.f) cute.setPosition({0.f, pos.y});
            if (pos.y < 0.f) cute.setPosition({pos.x, 0.f});
            if (pos.x + bounds.size.x > 800.f) cute.setPosition({800.f - bounds.size.x, pos.y});
            if (pos.y + bounds.size.y > 600.f) cute.setPosition({pos.x, 600.f - bounds.size.y});

            // Update falling objects
            for(auto& ob : objects){
                if(ob.active){
                    ob.update();
                }
            }
        } // <--- END OF GAME LOGIC

        // 3. Check if Game Over condition is met
        if (failure > 100 && !gameOver) {
            gameOver = true; // Freeze the game
        }

        // 4. DRAWING (Always runs so we can see the Game Over screen)
        window.clear(Color::Black);
        
        for(auto& obj : objects){
            obj.draw(window);
        }
        window.draw(cute);
        window.draw(scoreText);
        window.draw(failureText);
        
        if(gameOver){
            window.draw(gameOverText);
            
            // Optional: Close the window if the user presses Escape or Enter after game over
            if (Keyboard::isKeyPressed(Keyboard::Key::Escape) || Keyboard::isKeyPressed(Keyboard::Key::Enter)) {
                window.close();
            }
        }
        
        window.display();
    }