#ifndef PLAYER_H
#define PLAYER_H

#include "common.hpp"
#include "entity.hpp" 
#include "map.hpp"

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

    void processPlayerOnStairs();

    Vector2 getPosition();

    void placeInMap(const Map& map);

    void resetPlayer();
    void setMaxHealth();

    bool onElement(Map& map, const char element);
    bool onStairs(Map& map);

    void centralizePlayerOnStairs(Map& map);

    void updatePositionX(Map& map);

    void drawPlayer();
};

#endif