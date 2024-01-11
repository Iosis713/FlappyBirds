#include "Headers/Controllable.hpp"

Controllable::Controllable(sf::Vector2f position, float const width, float const height)
    : Moveable(position, width, height)
{};

bool Controllable::checkCollision(std::shared_ptr<Pipes> const checkedSprite)
{
    //checking of main object vertexes collision
    //left top vertex of the main object penetration
    if( (vertex_[0].x >= checkedSprite->getVertexes()[0].x) &&
        (vertex_[0].x <= checkedSprite->getVertexes()[1].x) &&
        (vertex_[0].y >= checkedSprite->getVertexes()[0].y) &&
        (vertex_[0].y <= checkedSprite->getVertexes()[2].y))
    {   
        collisionStatus_ = true;
    }
    //right top vertex of the main object penetration
    else if((vertex_[1].x >= checkedSprite->getVertexes()[0].x) &&
            (vertex_[1].x <= checkedSprite->getVertexes()[1].x) &&
            (vertex_[1].y >= checkedSprite->getVertexes()[0].y) &&
            (vertex_[1].y <= checkedSprite->getVertexes()[2].y))
    {
        collisionStatus_ = true;
    }
    //left bottom vertex of the main object penetration
    else if((vertex_[2].x >= checkedSprite->getVertexes()[0].x) &&
            (vertex_[2].x <= checkedSprite->getVertexes()[1].x) &&
            (vertex_[2].y >= checkedSprite->getVertexes()[0].y) &&
            (vertex_[2].y <= checkedSprite->getVertexes()[2].y))
    {
        collisionStatus_ = true;
    }
    //right bottom vertex of the main object penetration
    else if((vertex_[3].x >= checkedSprite->getVertexes()[0].x) &&
            (vertex_[3].x <= checkedSprite->getVertexes()[1].x) &&
            (vertex_[3].y >= checkedSprite->getVertexes()[0].y) &&
            (vertex_[3].y <= checkedSprite->getVertexes()[2].y))
    {
        collisionStatus_ = true;
    }
    //checking of the main objects intersection (event without vertexes inside)
    else if((((vertex_[0].y >= checkedSprite->getVertexes()[0].y) &&
              (vertex_[0].y <= checkedSprite->getVertexes()[2].y)) //upper edge 
                or
             ((vertex_[2].y >= checkedSprite->getVertexes()[0].y) &&
              (vertex_[2].y <= checkedSprite->getVertexes()[2].y))) //bottom edge
                and
             (((checkedSprite->getVertexes()[0].x >= vertex_[0].x) &&
              (checkedSprite->getVertexes()[1].x <= vertex_[1].x)) // left edge of collider
                or
             ((checkedSprite->getVertexes()[1].x >= vertex_[0].x) &&
              (checkedSprite->getVertexes()[1].x <= vertex_[1].x)))) // right edge of collider
    {
        collisionStatus_ = true;
    }
    //main object vertical edges (changes checkedSprite with main object)
    else if((((vertex_[0].x >= checkedSprite->getVertexes()[0].x) &&
              (vertex_[0].x <= checkedSprite->getVertexes()[1].x)) //left edge
                or
             ((vertex_[1].x >= checkedSprite->getVertexes()[0].x) &&
              (vertex_[1].x <= checkedSprite->getVertexes()[1].x))) //right edge
                and
            (((checkedSprite->getVertexes()[0].y >= vertex_[0].y) &&
              (checkedSprite->getVertexes()[0].y <= vertex_[2].y)) //top edge of collider
                or
             ((checkedSprite->getVertexes()[2].y >= vertex_[0].y) &&
              (checkedSprite->getVertexes()[2].y <= vertex_[2].y)))) //bottom edge of collider
    {
        collisionStatus_ = true;
    }

    //_________________________TOP PIPES_____________________________________________//
    

    else if( (vertex_[0].x >= checkedSprite->getTopVertexes()[0].x) &&
        (vertex_[0].x <= checkedSprite->getTopVertexes()[1].x) &&
        (vertex_[0].y >= checkedSprite->getTopVertexes()[0].y) &&
        (vertex_[0].y <= checkedSprite->getTopVertexes()[2].y))
    {
        collisionStatus_ = true;
    }
    //right top vertex of the main object penetration
    else if((vertex_[1].x >= checkedSprite->getTopVertexes()[0].x) &&
            (vertex_[1].x <= checkedSprite->getTopVertexes()[1].x) &&
            (vertex_[1].y >= checkedSprite->getTopVertexes()[0].y) &&
            (vertex_[1].y <= checkedSprite->getTopVertexes()[2].y))
    {
        collisionStatus_ = true;
    }
    //left bottom vertex of the main object penetration
    else if((vertex_[2].x >= checkedSprite->getTopVertexes()[0].x) &&
            (vertex_[2].x <= checkedSprite->getTopVertexes()[1].x) &&
            (vertex_[2].y >= checkedSprite->getTopVertexes()[0].y) &&
            (vertex_[2].y <= checkedSprite->getTopVertexes()[2].y))
    {
        collisionStatus_ = true;
    }
    //right bottom vertex of the main object penetration
    else if((vertex_[3].x >= checkedSprite->getTopVertexes()[0].x) &&
            (vertex_[3].x <= checkedSprite->getTopVertexes()[1].x) &&
            (vertex_[3].y >= checkedSprite->getTopVertexes()[0].y) &&
            (vertex_[3].y <= checkedSprite->getTopVertexes()[2].y))
    {
        collisionStatus_ = true;
    }
    //checking of the main objects intersection (event without vertexes inside)
    else if((((vertex_[0].y >= checkedSprite->getTopVertexes()[0].y) &&
              (vertex_[0].y <= checkedSprite->getTopVertexes()[2].y)) //upper edge 
                or
             ((vertex_[2].y >= checkedSprite->getTopVertexes()[0].y) &&
              (vertex_[2].y <= checkedSprite->getTopVertexes()[2].y))) //bottom edge
                and
             (((checkedSprite->getTopVertexes()[0].x >= vertex_[0].x) &&
              (checkedSprite->getTopVertexes()[1].x <= vertex_[1].x)) // left edge of collider
                or
             ((checkedSprite->getTopVertexes()[1].x >= vertex_[0].x) &&
              (checkedSprite->getTopVertexes()[1].x <= vertex_[1].x)))) // right edge of collider
    {
        collisionStatus_ = true;
    }
    //main object vertical edges (changes checkedSprite with main object)
    else if((((vertex_[0].x >= checkedSprite->getTopVertexes()[0].x) &&
              (vertex_[0].x <= checkedSprite->getTopVertexes()[1].x)) //left edge
                or
             ((vertex_[1].x >= checkedSprite->getTopVertexes()[0].x) &&
              (vertex_[1].x <= checkedSprite->getTopVertexes()[1].x))) //right edge
                and
            (((checkedSprite->getTopVertexes()[0].y >= vertex_[0].y) &&
              (checkedSprite->getTopVertexes()[0].y <= vertex_[2].y)) //top edge of collider
                or
             ((checkedSprite->getTopVertexes()[2].y >= vertex_[0].y) &&
              (checkedSprite->getTopVertexes()[2].y <= vertex_[2].y)))) //bottom edge of collider
    {
        collisionStatus_ = true;
    }
    else
    {
        collisionStatus_ = false;
    }
    return collisionStatus_;
}

void Controllable::draw(sf::RenderWindow& i_window)
{
    rectangle_.setFillColor(sf::Color::Magenta);
    rectangle_.setSize(sf::Vector2f(width_, height_));
    rectangle_.setPosition(position_);

    i_window.draw(rectangle_);
}

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

