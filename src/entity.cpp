#include "entity.hpp"

void Entity::movePosX(int moveX, Direction direction){
    if (direction == Direction::Right){
        posX += moveX;
    }
    else{
        posX -= moveX;
    }
}