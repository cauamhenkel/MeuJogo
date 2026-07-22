#ifndef ENTITY_H
#define ENTITY_H

#include "my_game.hpp"
#include "map.hpp"

enum class Direction{
    Left,
    Right
};

class Entity{
private:
    int m_posX {};
    int m_posY {};
    Direction direction {Direction::Right};

public:

};

#endif