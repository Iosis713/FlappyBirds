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

    Controllable bird(sf::Vector2f(500.f, 500.f), 40.f, 40.f);
    bird.setGravityStatus(true);    
    
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

        bird.jump();
        bird.updatePosition();
        bird.checkMapBoundaryCollision();
        bird.draw(window);
    
        pipesManager.drawAllPipes(window);
        
        for(auto& pipes : pipesManager.getPipes())
        {
            if(bird.checkCollision(pipes))
            {   
                pipesManager.stopAllPipes();
                while(!bird.getIsAlive())
                {
                    while(window.pollEvent(event))
                        {
                            if(event.type == sf::Event::Closed)
                            {
                                window.close();
                            }
                        }

                    if(bird.getPosition().y < (static_cast<float>(SCREEN_HEIGHT) - 2.5 * bird.getHeight()))
                    {
                        window.display();
                        {
                            using namespace std::chrono_literals;
                            std::this_thread::sleep_for(20ms);
                        }
                        window.clear();
                        bird.updatePosition();
                        pipesManager.drawAllPipes(window);
                        bird.draw(window);
                    }

                    else
                    {
                        bird.setGravityStatus(false);
                        bird.setVelocity(sf::Vector2f(0.0f, 0.0f));
                        window.clear();
                        bird.setPosition(sf::Vector2f(bird.getPosition().x,
                                                      static_cast<float>(SCREEN_HEIGHT) - 2.5 * bird.getHeight()));
                    
                        pipesManager.drawAllPipes(window);
                        bird.draw(window);
                        window.display();
                        
                        {
                            using namespace std::chrono_literals;
                            std::this_thread::sleep_for(250ms);
                        }
                    }
                }
            }
        }

        window.display();
        {
            using namespace std::chrono_literals;
            std::this_thread::sleep_for(20ms);
        }
        window.clear();
        pipesManager.reorganise();
    }

    return 0;
}

