#pragma once

#include "Moveable.hpp"
#include <chrono>
#include <thread>

class Controllable : public Moveable
{
protected:
    
    unsigned deltaTime; //dt from previous jump
    bool jumpAbility_ = true;
    const float jumpVelocity_ = 20.0f;
    const unsigned jumpUnabilityTime_ = 150; //ms
    const float maximumNegativeVerticalVelocity_ = -35.f; //upward is -Y direction
    std::chrono::time_point<std::chrono::steady_clock> previousJumpTime;

public:
    Controllable(sf::Vector2f position, float const width, float const height);
    Controllable(sf::Vector2f position, float const width, float const height, sf::Color color);
    void jump();
};
