#include "Headers/PipesManager.hpp"

PipesManager::PipesManager()
{
    manager_.reserve(6);
    manager_.push_back(Pipes(sf::Vector2f(static_cast<float>(SCREEN_WIDTH), 600.f),
                            80.f,
                            600.f));
}

void PipesManager::generatePipes()
{   
    manager_.push_back(Pipes(sf::Vector2f(static_cast<float>(SCREEN_WIDTH), 600.f),
                            80.f,
                            600.f));
    //auto iter = manager_.end();
    auto iter = manager_.begin();
    iter += manager_.size() - 1;
    //iter->setPosition(sf::Vector2f(500.f, 400.f));       
    iter->setPosition(sf::Vector2f(iter->getPosition().x,
                                   static_cast<float>(iter->getRandom())));
}

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

void PipesManager::drawAllPipes(sf::RenderWindow& i_window)
{
    for(auto& el : manager_)
    {   
        el.Pipes::updatePosition();
        el.Pipes::draw(i_window);
    }
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
    std::cout << xPosition << '\n';
    while(manager_.size() < manager_.capacity())
    {
        manager_.push_back(Pipes(sf::Vector2f(xPosition,
                            static_cast<float>(beginIter->getRandom())),
                            80.f,
                            600.f));

        xPosition -= (static_cast<float>(framesLimit_) * pipesVelocity - beginIter->getWidth());
    }
}

void PipesManager::reorganise()
{
    for(auto& pipes : manager_)
    {
        if(pipes.getPosition().x <= 0.0f - pipes.getWidth())
        {
            pipes.setPosition(sf::Vector2f(static_cast<float>(SCREEN_WIDTH),
                                           static_cast<float>(pipes.getRandom())));
        }
    }
}

