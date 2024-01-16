#include <chrono>
#include <iostream>
#include <thread>

#include <SFML/Graphics.hpp>
#include "Headers/Sprite.hpp"
#include "Headers/Moveable.hpp"
#include "Headers/Controllable.hpp"
#include "Headers/Pipes.hpp"
#include "Headers/PipesManager.hpp"


int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "FlappyBirds");

    Controllable testControllable(sf::Vector2f(500.f, 500.f), 40.f, 40.f);
    testControllable.setGravityStatus(true);    
    
    PipesManager pipesManager;
    pipesManager.initialize();

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

        testControllable.jump();
        testControllable.updatePosition();
        testControllable.checkMapBoundaryCollision();
        testControllable.draw(window);
    
        pipesManager.drawAllPipes(window);
        
        window.display();
        {
            using namespace std::chrono_literals;
            std::this_thread::sleep_for(33ms);
        }
        pipesManager.reorganise();
    }

    return 0;
}

