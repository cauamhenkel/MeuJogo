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
    bool m_enteredLevel {};

public:
    Player() {
        m_body.velX = Constants::tileWidth / 5;
    }
    void placeInMap(const Map& map);
    void resetPlayer();
    void setMaxHealth();
    void setEnteredLevel(bool entered);

    void updatePlayer(const Map& map);

    void updatePositionX(const Map& map);

    void processPlayerOnStairs(const Map& map);
    void centralizePlayerOnStairs(const Map& map);

    bool onElement(const Map& map, const char element);
    bool onStairs(const Map& map);
    bool onPlatform(const Map& map);
    bool elementAbove(const Map& map, const char element);
    bool elementBelow(const Map& map, const char element);

    bool hasEnteredLevel();
    Vector2 getPosition();

    void drawPlayer();
};

#endif