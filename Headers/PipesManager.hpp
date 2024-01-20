#pragma once

#include <vector>
#include <memory>
#include <algorithm>
#include "Pipes.hpp"

class PipesManager
{
protected:
    unsigned short frameCounter_ = 0;
    unsigned short framesLimit_ = 60;
    std::vector<Pipes> manager_;

public:
    PipesManager();
    ~PipesManager() = default;

    void drawAllPipes(sf::RenderWindow& i_window);
    void generatePipes();
    void increaseFrameCounter();
    void initialize();
    void reorganise();
    void stopAllPipes();    

    unsigned short getFrameCounter();
    unsigned short getFramesLimit();
    size_t getManagerSize();
    std::vector<Pipes> getPipes();
};

