#pragma once

#include <vector>
#include <memory>
#include "Pipes.hpp"

class PipesManager
{
protected:
    std::vector<Pipes> manager_;
    unsigned short frameCounter_ = 0;
    unsigned short framesLimit_ = 30;
public:
    PipesManager();

    void drawAllPipes(sf::RenderWindow& i_window);
    void generatePipes();
    void increaseFrameCounter();
    void reorganise();
    void initialize();

    unsigned short getFrameCounter();
    unsigned short getFramesLimit();
    std::vector<Pipes> getPipes();
    size_t getManagerSize();

};

