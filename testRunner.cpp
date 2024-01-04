#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>


#include "Headers/Sprite.hpp"


class SpriteFixture : public testing::TestWithParam<sf::Vector2f>
{
public:
protected:
    Sprite mSprite{sf::Vector2f(50.f, 100.f), 20.f, 100.f, sf::Color::Red};
};

TEST_P(SpriteFixture, TestSetPosition)
{
    sf::Vector2f param = GetParam();

    mSprite.setPosition(param);

    ASSERT_EQ(mSprite.getPosition(), param);
}

TEST(Sprite, getHeightTest)
{
    Sprite mSprite{sf::Vector2f(50.f, 100.f), 20.f, 70.f, sf::Color::Red}; 

    ASSERT_EQ(70.f, mSprite.getHeight());
}

TEST(Sprite, getWidthTest)
{
    Sprite mSprite{sf::Vector2f(50.f, 100.f), 60.f, 70.f, sf::Color::Red};
    
    ASSERT_EQ(60.f, mSprite.getWidth());
}


INSTANTIATE_TEST_CASE_P(TestingSetPosition, SpriteFixture, testing::Values(sf::Vector2f(20, 30),
                                                        sf::Vector2f(60, -10),
                                                        sf::Vector2f(-20, -30)));


int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

