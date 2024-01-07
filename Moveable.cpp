#include "Headers/Moveable.hpp"

Moveable::Moveable(sf::Vector2f position, float const width, float const height)
    : Sprite(position, width, height)
{};

Moveable::Moveable(sf::Vector2f position, float const width, float const height, sf::Color color)
    : Sprite(position, width, height, color)
{};

Moveable::Moveable(sf::Vector2f position, float const width, float const height, sf::Vector2f velocity)
    : Sprite(position, width, height)
    , velocity_(velocity)
{};

Moveable::Moveable(sf::Vector2f position, float const width, float const height, sf::Color color, sf::Vector2f velocity)
    : Sprite(position, width, height, color)
    , velocity_(velocity)
{};

sf::Vector2f Moveable::getVelocity() const
{
    return this-> velocity_;
};

void Moveable::setGravityStatus(bool status)
{
    gravityStatus_ = status;
}

void Moveable::setVelocity(sf::Vector2f velocity)
{
    velocity_ = velocity;
};

void Moveable::updatePosition()
{
    if(gravityStatus_)
    {
        velocity_.y += gravity_;
    }

    position_ += velocity_;
}

