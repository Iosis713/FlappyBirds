#include <chrono>
#include <iostream>
#include <thread>

#include <SFML/Graphics.hpp>
#include "Headers/Sprite.hpp"
#include "Headers/Moveable.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "FlappyBirds");

    Sprite testSprite(sf::Vector2f(800.f, 350.f), 50.f, 80.f, sf::Color::Magenta);
    
    Sprite testSprite_2(sf::Vector2f(400.f, 200.f), 30.f, 70.f);

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

        testSprite.draw(window);
        testSprite_2.draw(window);

        window.display();
        {
            using namespace std::chrono_literals;
            std::this_thread::sleep_for(20ms);
        }   
    }

    return 0;
}

