#include "Headers/PipesManager.hpp"

PipesManager::PipesManager()
{
    manager_.reserve(7);
    manager_.push_back(Pipes(sf::Vector2f(static_cast<float>(SCREEN_WIDTH), 600.f),
                            84.f,
                            650.f));
}

/*__________________________________GETTERS_____________________________________*/

unsigned short PipesManager::getFrameCounter()
{
    return this->frameCounter_;
}

unsigned short PipesManager::getFramesLimit()
{
    return this->framesLimit_;
}

size_t PipesManager::getManagerSize()
{
    return this->manager_.size();
}

std::vector<Pipes> PipesManager::getPipes()
{
    return this-> manager_;
}

/*_____________________________________OTHER FUNCTIONS ___________________________________*/

void PipesManager::drawAllPipes(sf::RenderWindow& i_window)
{
    for(auto& el : manager_)
    {   
        el.Pipes::updatePosition();
        el.Pipes::draw(i_window);
    }
}

void PipesManager::generatePipes()
{   
    manager_.push_back(Pipes(sf::Vector2f(static_cast<float>(SCREEN_WIDTH), 600.f),
                            85.f,
                            650.f));
    auto iter = manager_.begin();
    iter += manager_.size() - 1;      
    iter->setPosition(sf::Vector2f(iter->getPosition().x,
                                   static_cast<float>(iter->getRandom())));
}

void PipesManager::increaseFrameCounter()
{
    if(frameCounter_ <= framesLimit_)
    {
        frameCounter_++;
    }
    else
    {
        frameCounter_ = 0;
    }
}

void PipesManager::initialize()
{
    
    auto beginIter = manager_.begin();
    auto pipesVelocity = beginIter->getVelocity().x;
    auto xPosition = static_cast<float>(SCREEN_WIDTH)
                   - static_cast<float>(framesLimit_) * pipesVelocity
                   + beginIter->getWidth();

    while(manager_.size() < 6)
    {
        manager_.push_back(Pipes(sf::Vector2f(xPosition,
                            static_cast<float>(beginIter->getRandom())),
                            84.f,
                            650.f));

        xPosition -= (static_cast<float>(framesLimit_) * pipesVelocity - beginIter->getWidth());
    }
}

void PipesManager::reorganise()
{
    for(auto& pipes : manager_)
    {   
        if(pipes.getPosition().x <= 0.0f and 
           pipes.getPosition().x > pipes.getVelocity().x) 
        {
            pipes.setIsGone(true);
        }
        else if(pipes.getPosition().x > 0.0f)
        {
            pipes.setIsGone(false);
        }
    }
    
    for(auto& pipes : manager_)
    {
        if(pipes.getPosition().x <= framesLimit_ * pipes.getVelocity().x
                                    - pipes.getWidth())
        {
            pipes.setPosition(sf::Vector2f(static_cast<float>(SCREEN_WIDTH),
                                           static_cast<float>(pipes.getRandom())));
        }
    }
}

void PipesManager::stopAllPipes()
{
    for(auto& pipes : manager_)
    {
        pipes.setVelocity(sf::Vector2f(0.0f, 0.0f));
    }
}

