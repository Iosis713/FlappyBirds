#include "Headers/Moveable.hpp"

Moveable::Moveable(sf::Vector2f position, float const width, float const height)
    : Sprite(position, width, height)
{};

Moveable::Moveable(sf::Vector2f position, float const width, float const height, sf::Color color)
    : Sprite(position, width, height, color)
{};

sf::Vector2f Moveable::getVelocity() const
{
    return this-> velocity_;
};

void Moveable::setVelocity(sf::Vector2f velocity)
{
    velocity_ = velocity;
};

void Moveable::updatePosition()
{
    position_ += velocity_;
}

