#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <SFML/Graphics.hpp>
#include "Headers/Sprite.hpp"
#include "Headers/Moveable.hpp"

/*_____________________________________ SPRITE class _________________________________*/

class SpriteFixture : public testing::TestWithParam<sf::Vector2f>
{
public:
protected:
    Sprite mSprite{sf::Vector2f(50.f, 100.f), 20.f, 100.f};
};

TEST_P(SpriteFixture, TestingSetPosition)
{
    sf::Vector2f param = GetParam();

    mSprite.setPosition(param);

    ASSERT_EQ(mSprite.getPosition(), param);

    TearDown();
}

TEST_P(SpriteFixture, TestingMapColision)
{
    sf::Vector2f param = GetParam();

    mSprite.setPosition(param);

    ASSERT_TRUE(mSprite.checkMapBoundaryCollision());

    TearDown();
}

TEST_F(SpriteFixture, vertexesUpdateTest)
{
    mSprite.updateVertexes();

    std::array<sf::Vector2f, 4> expectedVertexes;
    expectedVertexes[0] = sf::Vector2f{50.f, 100.f};
    expectedVertexes[1] = sf::Vector2f{50.f + 20.f, 100.f};
    expectedVertexes[2] = sf::Vector2f{50.f, 100.f + 100.f};
    expectedVertexes[3] = sf::Vector2f{50.f + 20.f, 100.f + 100.f};

    ASSERT_EQ(expectedVertexes, mSprite.getVertexes());
}

INSTANTIATE_TEST_CASE_P(TestingMapCollision, SpriteFixture, testing::Values(
                                                        sf::Vector2f(0.0f, 0.1f), //vertex
                                                        sf::Vector2f(-1.5f, 700.f), //left side
                                                        sf::Vector2f(SCREEN_WIDTH - 47.3, 700.f), // right side
                                                        sf::Vector2f(500.f, -0.73f), // top side
                                                        sf::Vector2f(500.f, SCREEN_HEIGHT - 99.1f), // bottom side
                                                        sf::Vector2f(SCREEN_WIDTH -50.f, SCREEN_HEIGHT - 100.f), // right bottom vertex
                                                        sf::Vector2f(0.0f, SCREEN_HEIGHT - 100.f), // left bottom vertex
                                                        sf::Vector2f(SCREEN_WIDTH - 50.f, 0.0f)));

TEST(CollisionTest, LeftTopVertexInteracting)
{
    Sprite mSprite(sf::Vector2f(300.f, 300.f), 100.f, 100.f);
    auto collider_ptr = std::make_shared<Sprite>(sf::Vector2f(200.f, 200.f), 200.f, 200.f);
    
    bool result = mSprite.checkCollision(collider_ptr);

    ASSERT_TRUE(result);
}

TEST(CollisionTest, RightTopVertexInteracting)
{
    Sprite mSprite(sf::Vector2f(200.f, 200.f), 100.f, 100.f);
    auto collider_ptr = std::make_shared<Sprite>(sf::Vector2f(200.f, 200.f), 200.f, 200.f);
    
    bool result = mSprite.checkCollision(collider_ptr);

    ASSERT_TRUE(result);
}

TEST(CollisionTest, LeftBottomVertexInteracting)
{
    Sprite mSprite(sf::Vector2f(200.f, 200.f), 100.f, 100.f);
    auto collider_ptr = std::make_shared<Sprite>(sf::Vector2f(250.f, 250.f), 70.f, 70.f);
    
    bool result = mSprite.checkCollision(collider_ptr);

    ASSERT_TRUE(result);
}

TEST(CollisionTest, RightBottomVertexInteracting)
{
    Sprite mSprite(sf::Vector2f(200.f, 200.f), 100.f, 100.f);
    auto collider_ptr = std::make_shared<Sprite>(sf::Vector2f(250.f, 250.f), 100.f, 100.f);
    
    bool result = mSprite.checkCollision(collider_ptr);

    ASSERT_TRUE(result);
}

TEST(CollisionTest, NoInteraction)
{
    Sprite mSprite(sf::Vector2f(200.f, 200.f), 100.f, 100.f);
    auto collider_ptr = std::make_shared<Sprite>(sf::Vector2f(400.f, 400.f), 100.f, 100.f);
    
    bool result = mSprite.checkCollision(collider_ptr);

    ASSERT_FALSE(result);
}

TEST(CollisionTest, HorizontalEdges)
{
    Sprite mSprite(sf::Vector2f(200.f, 200.f), 600.f, 100.f);
    auto collider_ptr = std::make_shared<Sprite>(sf::Vector2f(250.f, 50.f), 20.f, 600.f);
    
    bool result = mSprite.checkCollision(collider_ptr);

    ASSERT_TRUE(result);
}

TEST(CollisionTest, VerticalEdges)
{
    Sprite mSprite(sf::Vector2f(200.f, 200.f), 20.f, 600.f);
    auto collider_ptr = std::make_shared<Sprite>(sf::Vector2f(50.f, 300.f), 600.f, 20.f);
    
    bool result = mSprite.checkCollision(collider_ptr);

    ASSERT_TRUE(result);
}


/*________________________ MOVEABLE class ________________________________________*/

class MoveableFixture : public testing::TestWithParam<sf::Vector2f>
{
public:
protected:
    Moveable mMoveable{sf::Vector2f(600.f, 300.f), 30.f, 70.f};
};

TEST_P(MoveableFixture, setVelocityTest)
{
    sf::Vector2f param = GetParam();
    
    mMoveable.setVelocity(param);

    ASSERT_EQ(mMoveable.getVelocity(), param);
    TearDown();
}

INSTANTIATE_TEST_CASE_P(TestingSetVelocity, MoveableFixture, testing::Values(sf::Vector2f(10, 40),
                                                                             sf::Vector2f(0, 30),
                                                                             sf::Vector2f(0, -20),
                                                                             sf::Vector2f(10, 0),
                                                                             sf::Vector2f(-17.6, 0),
                                                                             sf::Vector2f(-11.2, -23.2)));

TEST_P(MoveableFixture, updatePositionTest)
{
    sf::Vector2f param = GetParam();//velocity vector
    sf::Vector2f initialPosition = mMoveable.getPosition();

    mMoveable.setVelocity(param);
    mMoveable.updatePosition();

    ASSERT_EQ(mMoveable.getPosition(), initialPosition + param);
    TearDown();
}

INSTANTIATE_TEST_CASE_P(TestingUpdatePosition, MoveableFixture,
        testing::Values(sf::Vector2f(17.6, 41),
                        sf::Vector2f(0.0, 37.1),
                        sf::Vector2f(0.0, -27.16),
                        sf::Vector2f(12.9, 0.0),
                        sf::Vector2f(-27.62, 0.0),
                        sf::Vector2f(-51.2, -43.2)));

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

