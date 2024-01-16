#include "Headers/Sprite.hpp"

Sprite::Sprite(sf::Vector2f position, float const width, float const height)
    : position_(position)
    , width_(width)
    , height_(height)
{
    updateVertexes();
};

bool Sprite::checkCollision(std::shared_ptr<Sprite> const checkedSprite)
{
    //checking of main object vertexes collision
    //left top vertex of the main object penetration
    if( (vertex_[0].x >= checkedSprite->getVertexes()[0].x) &&
        (vertex_[0].x <= checkedSprite->getVertexes()[1].x) &&
        (vertex_[0].y >= checkedSprite->getVertexes()[0].y) &&
        (vertex_[0].y <= checkedSprite->getVertexes()[2].y))
    {
        return true;
    }
    //right top vertex of the main object penetration
    else if((vertex_[1].x >= checkedSprite->getVertexes()[0].x) &&
            (vertex_[1].x <= checkedSprite->getVertexes()[1].x) &&
            (vertex_[1].y >= checkedSprite->getVertexes()[0].y) &&
            (vertex_[1].y <= checkedSprite->getVertexes()[2].y))
    {
        return true;
    }
    //left bottom vertex of the main object penetration
    else if((vertex_[2].x >= checkedSprite->getVertexes()[0].x) &&
            (vertex_[2].x <= checkedSprite->getVertexes()[1].x) &&
            (vertex_[2].y >= checkedSprite->getVertexes()[0].y) &&
            (vertex_[2].y <= checkedSprite->getVertexes()[2].y))
    {
        return true;
    }
    //right bottom vertex of the main object penetration
    else if((vertex_[3].x >= checkedSprite->getVertexes()[0].x) &&
            (vertex_[3].x <= checkedSprite->getVertexes()[1].x) &&
            (vertex_[3].y >= checkedSprite->getVertexes()[0].y) &&
            (vertex_[3].y <= checkedSprite->getVertexes()[2].y))
    {
        return true;
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
        return true;
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
        return true;
    }
    else
    {
        return false;
    }
}

bool Sprite::checkMapBoundaryCollision()
{
    //top boundary
    if(position_.y <= 0.0 or
       position_.y >= (static_cast<float>(SCREEN_HEIGHT) - height_)   or
       position_.x <= 0.0 or
       position_.x >= (static_cast<float>(SCREEN_HEIGHT) - width_))
    {
        collisionStatus_ = true;
    }
    else if(position_ == sf::Vector2f(0.0f, 0.0f))
    {
        collisionStatus_ = true;
    }
    else
    {
        collisionStatus_ = false;
    }
    return collisionStatus_;
}


void Sprite::draw(sf::RenderWindow& i_window)
{
    //sf::RectangleShape rectangle_;
    rectangle_.setFillColor(sf::Color::Yellow);
    rectangle_.setSize(sf::Vector2f(width_, height_));
    rectangle_.setPosition(position_);
    i_window.draw(rectangle_);
}

void Sprite::updateVertexes()
{
    vertex_[0] = position_;
    vertex_[1] = position_ + sf::Vector2f{width_, 0.0};
    vertex_[2] = position_ + sf::Vector2f{0.0, height_};
    vertex_[3] = position_ + sf::Vector2f{width_, height_};
}

/*___________________________________GETTERS______________________________*/

bool Sprite::getCollisionStatus()
{   
   return this-> collisionStatus_;
}

float Sprite::getHeight() const
{
    return this-> height_;
};

float Sprite::getWidth() const
{
    return this-> width_;
};

sf::Vector2f Sprite::getPosition() const 
{
    return this -> position_;
};

std::array<sf::Vector2f, 4> Sprite::getVertexes()
{
    return this-> vertex_;
}

/*__________________________________SETTERS____________________________*/

void Sprite::setCollisionStatus(bool status)
{
    collisionStatus_ = status;
}

void Sprite::setPosition(sf::Vector2f position)
{    
    position_ = position;
};
