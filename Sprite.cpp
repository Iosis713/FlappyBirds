#include "Headers/Sprite.hpp"

Sprite::Sprite(sf::Vector2f position, float const width, float const height, sf::Color color)
    : position_(position)
    , width_(width)
    , height_(height)
{
    rectangle_.setFillColor(color);
    rectangle_.setSize(sf::Vector2f(width_, height_));
    rectangle_.setPosition(position_);
};

void Sprite::setPosition(sf::Vector2f position)
{    
    position_ = position;
};

sf::Vector2f Sprite::getPosition() 
{
    return this -> position_;
};
