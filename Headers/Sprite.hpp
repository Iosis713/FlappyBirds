#pragma once

#include <iostream>

#include "Global.hpp"
#include <SFML/Graphics.hpp>
#include <memory>

class Sprite
{
protected:
    bool collisionStatus_ = false;
    sf::Vector2f position_;
    float const width_;
    float const height_;
    sf::RectangleShape rectangle_;
    std::array<sf::Vector2f, 4> vertex_;// 0 -leftTop, 1 - rightTop, 2 -leftBottom, 3-rightBottom

public:
    Sprite(sf::Vector2f position, float const width, float const height);
    Sprite(sf::Vector2f position, float const width, float const height, sf::Color color);
    
    bool getCollisionStatus();
    float getHeight() const;
    float getWidth() const;
    sf::Vector2f getPosition() const;
    std::array<sf::Vector2f, 4> getVertexes();

    void setPosition(sf::Vector2f position);
    void setCollisionStatus(bool status);
    
    bool checkCollision(std::shared_ptr<Sprite> checkedSprite);
    virtual void draw(sf::RenderWindow& i_window);
    void updateVertexes();
};

