#ifndef PLAYER_H
#define PLAYER_H

#include "common.hpp"
#include "entity.hpp" 
#include "map.hpp"

class Player{
private:
    static constexpr int playerHeight {Constants::tileHeight};
    static constexpr int playerWidth {Constants::tileWidth};

    static constexpr int maxHealth {3};

    static constexpr double velOnStairs {Constants::tileHeight/5};

    Entity m_body {};
    int m_health {maxHealth};

public:
    Player() {
        m_body.velX = Constants::tileWidth / 5;
    }

    void updatePlayer(const Map& map);

    void processPlayerOnStairs(const Map& map);

    Vector2 getPosition();

    void placeInMap(const Map& map);

    void resetPlayer();
    void setMaxHealth();

    bool onElement(const Map& map, const char element);
    bool onStairs(const Map& map);
    bool elementAbove(const Map& map, const char element);
    bool elementBelow(const Map& map, const char element);

    void centralizePlayerOnStairs(const Map& map);

    void updatePositionX(const Map& map);

    void drawPlayer();
};

#endif