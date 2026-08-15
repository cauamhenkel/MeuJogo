#include "entity.hpp"

void Entity::updatePosX(){
    posX += velX;
}

void Entity::movePosX(int moveX, Direction direction){
    if (direction == Direction::Right){
        posX += moveX;
    }
    else{
        posX -= moveX;
    }
}