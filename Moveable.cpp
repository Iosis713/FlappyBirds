#include "Headers/Moveable.hpp"

Moveable::Moveable(sf::Vector2f position, float const width, float const height)
    : Sprite(position, width, height)
{};

Moveable::Moveable(sf::Vector2f position, float const width, float const height, sf::Vector2f velocity)
    : Sprite(position, width, height)
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

void Moveable::draw(sf::RenderWindow& i_window)
{
    sf::RectangleShape rectangle_;
    rectangle_.setFillColor(sf::Color::Red);
    rectangle_.setSize(sf::Vector2f(width_, height_));
    rectangle_.setPosition(position_);

    i_window.draw(rectangle_);
}

void Moveable::updatePosition()
{
    if(gravityStatus_)
    {
        velocity_.y += gravity_;
    }

    position_ += velocity_;
    updateVertexes();
}

