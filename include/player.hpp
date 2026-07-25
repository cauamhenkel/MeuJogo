#ifndef PLAYER_H
#define PLAYER_H

#include "game.hpp"
#include "entity.hpp" // includes map.hpp

class Player{
private:
    static constexpr int maxHealth {3};

    Entity m_body {};
    int m_health {maxHealth};

public:
    Player() {
        m_body.velX = Constants::tileWidth / 5;
    }

    void placeInMap(const Map& map);
    void drawPlayer();

    void setMaxHealth();
    void updatePositionX();
};

void updatePlayer(Player& player);

#endif