#ifndef PLAYER_H
#define PLAYER_H

#include "game.hpp"
#include "entity.hpp" // includes map.hpp

class Player{
private:
    Entity m_body;

public:
    Player() {
        m_body.velX = Constants::tileWidth / 5;
    }

    void placeInMap(const Map& map);
    void drawPlayer();

    void updatePositionX();
};

void updatePlayer(Player& player);

#endif