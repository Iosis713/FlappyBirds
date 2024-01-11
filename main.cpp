#include <chrono>
#include <iostream>
#include <thread>

#include <SFML/Graphics.hpp>
#include "Headers/Sprite.hpp"
#include "Headers/Moveable.hpp"
#include "Headers/Controllable.hpp"
#include "Headers/Pipes.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "FlappyBirds");

    Sprite testSprite(sf::Vector2f(800.f, 350.f), 50.f, 80.f);
    
    Moveable testMoveable(sf::Vector2f(400.f, 200.f), 30.f, 70.f);
    testMoveable.setVelocity(sf::Vector2f(5.0, 0.0));
    
    Controllable testControllable(sf::Vector2f(500.f, 500.f), 40.f, 40.f);
    testControllable.setGravityStatus(true);

    std::shared_ptr<Pipes> testPipes_ptr = std::make_shared<Pipes>(sf::Vector2f(1000.f, 600.f), 100.f, 600.f);    

    //unsigned deltaTime;
    //std::chrono::time_point<std::chrono::steady_clock> previousTime = std::chrono::steady_clock::now();

    while(window.isOpen())
    {
        sf::Event event;

        //close window
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        window.clear();
        
        //previousTime = std::chrono::steady_clock::now();

        /*do{
            testControllable.jump();
            deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - previousTime).count(); 
        }while(FRAME_DURATION > deltaTime);
        */

        testControllable.jump();
        testControllable.updatePosition();
        testControllable.checkCollision(testPipes_ptr);
        testControllable.checkMapBoundaryCollision();
        testControllable.getCollisionStatus();
        testControllable.draw(window);
        
        testSprite.draw(window);
        
        testMoveable.updatePosition();
        testMoveable.draw(window);
        
        testPipes_ptr->updatePosition();
        testPipes_ptr->draw(window);

        window.display();
        {
            using namespace std::chrono_literals;
            std::this_thread::sleep_for(50ms);
        }   
    }

    return 0;
}

