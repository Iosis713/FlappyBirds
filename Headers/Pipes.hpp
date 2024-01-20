#pragma once

#include <random>

#include "Moveable.hpp"

class Pipes : public Moveable
{
protected:
    const int maximumYPosition_ = SCREEN_HEIGHT - 150;
    const int pipesClearance_ = 300;
    const int minimumYPosition_ = 150 + pipesClearance_;
    std::array<sf::Vector2f, 4> topVertex_;// 0 -leftTop, 1 - rightTop, 2 -leftBottom, 3-rightBottom
    bool passedScreen = false;
    
public:

    Pipes(sf::Vector2f position, float const width, float const height);
    ~Pipes() override = default; 
    
    void draw(sf::RenderWindow& i_window) override;
    void updateVertexes() override;
    void updatePosition() override;
    
    void setIsGone(bool status);
    bool isGone();
    int getRandom();
    int getPipesClearance() const;   
    std::array<sf::Vector2f, 4> getTopVertexes() const;
    

};

