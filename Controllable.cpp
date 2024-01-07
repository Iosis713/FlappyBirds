#include "Headers/Controllable.hpp"

Controllable::Controllable(sf::Vector2f position, float const width, float const height)
    : Moveable(position, width, height)
{};

Controllable::Controllable(sf::Vector2f position, float const width, float const height, sf::Color color)
    : Moveable(position, width, height, color)
{};


void Controllable::jump()
{
    if((sf::Keyboard::isKeyPressed(sf::Keyboard::Space) or
        sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        and 
        jumpAbility_)
    {   
        if(velocity_.y - jumpVelocity_ > maximumNegativeVerticalVelocity_)
        {
            velocity_.y -= jumpVelocity_;
        }
        else
        {
            velocity_.y = maximumNegativeVerticalVelocity_;
        }

        previousJumpTime = std::chrono::steady_clock::now();
        jumpAbility_ = false;
    }

    deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - previousJumpTime).count();
    
    if(deltaTime > jumpUnabilityTime_)
    {
        jumpAbility_ = true;
    }
}

