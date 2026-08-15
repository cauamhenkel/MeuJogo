#ifndef ENTITY_H
#define ENTITY_H

#include "common.hpp"
#include "map.hpp"

enum class Direction{
    Left,
    Right
};

enum class EntityState{
    InGround,
    InAir,
    InStairs
};

struct Entity{
    static constexpr float gravity {Constants::tileHeight / 22.0};

    int posX {};
    double velX {};
    double accX {};
    int posY {};
    double velY {};
    double accY {};
    Direction direction {Direction::Right};
    EntityState state {EntityState::InGround};

    void updatePosX();
    void updatePosY();
    void movePosX(int moveX, Direction direction);
};

#endif