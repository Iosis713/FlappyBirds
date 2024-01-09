#include "Headers/Pipes.hpp"

Pipes::Pipes(sf::Vector2f position, float const width, float const height)
    : Moveable(position, width, height)
{
    setVelocity(sf::Vector2f(-5.0f, 0.0f));
};

void Pipes::draw(sf::RenderWindow& i_window)
{   
    rectangle_.setFillColor(sf::Color::Green);
    rectangle_.setPosition(position_);
    rectangle_.setSize(sf::Vector2f(width_, height_));

    i_window.draw(rectangle_);

    rectangle_.setPosition(sf::Vector2f(position_.x, position_.y
                                                      - height_
                                                      - static_cast<float>(pipesClearance_)));

    i_window.draw(rectangle_);
}

void Pipes::updateVertexes()
{
    Sprite::updateVertexes();
    
    sf::Vector2f auxiliaryVector{0.0, height_ + pipesClearance_};

    topVertex_[0] = position_ - auxiliaryVector;
    topVertex_[1] = position_ + sf::Vector2f{width_, 0.0} - auxiliaryVector;
    topVertex_[2] = position_ + sf::Vector2f{0.0, height_} - auxiliaryVector;
    topVertex_[3] = position_ + sf::Vector2f{width_, height_} - auxiliaryVector;

}

void Pipes::updatePosition()
{
    Moveable::updatePosition();
    Pipes::updateVertexes();
}

unsigned short Pipes::getPipesClearance() const
{
    return this-> pipesClearance_;
}

std::array<sf::Vector2f, 4> Pipes::getTopVertexes() const
{
    return this-> topVertex_;
}

