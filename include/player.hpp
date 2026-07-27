#ifndef PLAYER_H
#define PLAYER_H

#include "game.hpp"
#include "entity.hpp" // includes map.hpp

class Player{
private:
    static constexpr int maxHealth {3};

    static constexpr double velOnStairs {Constants::tileHeight/5};

    Entity m_body {};
    int m_health {maxHealth};

public:
    Player() {
        m_body.velX = Constants::tileWidth / 5;
    }

    void updatePlayer(Map& map);

    void placeInMap(const Map& map);
    void setMaxHealth();

    bool onElement(Map& map, const char element);
    bool onStairs(Map& map);

    void centralizePlayerOnStairs(Map& map);

    void updatePositionX();

    void processPlayerOnStairs();

    void drawPlayer();
};

#endif