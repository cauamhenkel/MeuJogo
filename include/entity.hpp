#ifndef ENTITY_H
#define ENTITY_H

#include "my_game.hpp"
#include "map.hpp"

enum class Direction{
    Left,
    Right
};

struct Entity{
    static constexpr float gravity {Constants::tileHeigth / 22};

    int posX {};
    double velX {};
    double accX {};
    int posY {};
    double velY {};
    double accY {};
    Direction direction {Direction::Right};

    void movePosX(int moveX, Direction direction);
};

#endif