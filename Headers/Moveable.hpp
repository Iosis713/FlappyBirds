#pragma once

#include "Sprite.hpp"

#include <SFML/Graphics.hpp>

class Moveable : public Sprite
{
protected:
    sf::Vector2f velocity_;
    const float gravity_ = 2.5f;
    bool gravityStatus_ = false; //not required for blocks

public:
    Moveable(sf::Vector2f position, float const width, float const height);
    Moveable(sf::Vector2f position, float const width, float const height, sf::Vector2f velocity);
    sf::Vector2f getVelocity() const;
    
    void setGravityStatus(bool status);
    void setVelocity(sf::Vector2f velocity);
    void draw(sf::RenderWindow& i_window) override;  
    void virtual updatePosition();
};

