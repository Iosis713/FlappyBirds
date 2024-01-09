#pragma once

#include "Moveable.hpp"

class Pipes : public Moveable
{
protected:
    unsigned short const pipesClearance_ = 400;
    std::array<sf::Vector2f, 4> topVertex_;// 0 -leftTop, 1 - rightTop, 2 -leftBottom, 3-rightBottom
public:

    Pipes(sf::Vector2f position, float const width, float const height);
    

    void draw(sf::RenderWindow& i_window) override;
    void updateVertexes() override;
    void updatePosition() override;
    unsigned short getPipesClearance() const;   
    std::array<sf::Vector2f, 4> getTopVertexes() const;
};

