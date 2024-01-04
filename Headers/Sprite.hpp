#pragma once

#include <iostream>

#include "Global.hpp"
#include <SFML/Graphics.hpp>

class Sprite
{
protected:
    sf::Vector2f position_;
    float const width_;
    float const height_;
    sf::RectangleShape rectangle_;


public:
    Sprite(sf::Vector2f position, float const width, float const height, sf::Color color);
    
    float getHeight() const;
    float getWidth() const;
    sf::Vector2f getPosition() const;
    
    void setPosition(sf::Vector2f position);
    
    virtual void draw(sf::RenderWindow& i_window);

};

