#include "player.hpp"

/* Class functions */

void Player::placeInMap(const Map& map){
    const MapGrid& mapGrid = map.getTiles();
    const int horizontalTiles {map.getHorizontalTiles()};
    const int verticalTiles {map.getVerticalTiles()};

    for (size_t row {0} ; row < static_cast<size_t>(verticalTiles) ; ++row){
        for (size_t col {0} ; col < static_cast<size_t>(horizontalTiles) ; ++col){
            if (mapGrid[row][col] == 'P'){
                m_body.posX = col * Constants::tileWidth;
                m_body.posY = row * Constants::tileHeight;
            }
        }
    }
}

void Player::resetPlayer(){
    m_body.state = EntityState::InGround;
}

void Player::setMaxHealth(){
    m_health = Player::maxHealth;
}

void Player::setEnteredLevel(bool entered){
    m_enteredLevel = entered;
}

void Player::updatePlayer(const Map& map){
    if ((IsKeyPressed(KEY_W) || IsKeyPressed(KEY_S)) && (onStairs(map) || onPlatform(map))){
        m_body.state = EntityState::InStairs;
        centralizePlayerOnStairs(map);
    }
    
    if (m_body.state == EntityState::InGround || m_body.state == EntityState::InAir){
        updatePositionX(map);
    }
    
    if (m_body.state == EntityState::InStairs){
        processPlayerOnStairs(map);
    }
}

void Player::updatePositionX(const Map& map){
    int mapWidthPixels = map.getHorizontalTiles() * Constants::tileWidth;

    if (((m_body.posX + Constants::tileWidth) < mapWidthPixels) && IsKeyDown(KEY_D)){
        m_body.movePosX(m_body.velX, Direction::Right);
    }
    if ((m_body.posX) > 0 && IsKeyDown(KEY_A)){
        m_body.movePosX(m_body.velX, Direction::Left);
    }
}

void Player::processPlayerOnStairs(const Map& map){
    if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_A)){
        m_body.state = EntityState::InAir;
    }
    if (IsKeyDown(KEY_W) && (elementAbove(map, Elements::stair) || elementAbove(map, Elements::platform))){
        m_body.posY -= Player::velOnStairs;
    }
    if (IsKeyDown(KEY_S) && (elementBelow(map, Elements::stair) || elementBelow(map, Elements::platform))){
        m_body.posY += Player::velOnStairs;
    }
}

void Player::centralizePlayerOnStairs(const Map& map){
    // Test only on the left side
    int posXLeftGrid {(m_body.posX) / Constants::tileWidth};
    int posYGridHead {(m_body.posY) / Constants::tileHeight};
    int posYGridFeet {(m_body.posY + Player::playerHeight - 1) / Constants::tileWidth};

    char farLeftHead {map.tileAt(posYGridHead, posXLeftGrid)};
    char farLeftFeet {map.tileAt(posYGridFeet, posXLeftGrid)};

    bool touchingStairFarLeft {farLeftHead == Elements::stair || farLeftHead == Elements::platform
                            || farLeftFeet == Elements::stair || farLeftFeet == Elements::platform};
    if (touchingStairFarLeft){
        m_body.posX -= (m_body.posX % Constants::tileWidth);
    }
    // if isn't in the left side, the player must be colliding with his right side
    else{
        m_body.posX -= (m_body.posX % Constants::tileWidth);
        m_body.posX += Constants::tileWidth;
    }
}

bool Player::onElement(const Map& map, const char element){
    int posXLeftGrid {(m_body.posX) / Constants::tileWidth};
    int posXRightGrid {(m_body.posX + Player::playerWidth - 1) / Constants::tileWidth};
    int posYHeadGrid {(m_body.posY) / Constants::tileHeight};
    int posYFeetGrid {(m_body.posY + Player::playerHeight - 1) / Constants::tileHeight};

    // Basically is a loop that check every grid tile the player is inside (generally 2x2)
    for (int row {posYHeadGrid} ; row <= posYFeetGrid ; ++row){
        for (int col {posXLeftGrid} ; col <= posXRightGrid ; ++col){
            if (map.tileAt(row, col) == element){
                return true;
            }
        }
    }
    return false;
}

bool Player::onStairs(const Map& map){
    return (onElement(map, Elements::stair));
}

bool Player::onPlatform(const Map& map){
    return (onElement(map, Elements::platform));
}

bool Player::elementAbove(const Map& map, const char element){
    int posXLeftGrid {(m_body.posX) / Constants::tileWidth};
    int posXRightGrid {(m_body.posX + Player::playerWidth - 1) / Constants::tileWidth};
    int posYAboveHeadGrid {(m_body.posY - 1) / Constants::tileHeight};

    // Basically is a loop that check every grid tile the player is inside (generally 2x2)
    for (int col {posXLeftGrid} ; col <= posXRightGrid ; ++col){
        if (map.tileAt(posYAboveHeadGrid, col) == element){
            return true;
        }
    }
    return false;
}

bool Player::elementBelow(const Map& map, const char element){
    int posXLeftGrid {(m_body.posX) / Constants::tileWidth};
    int posXRightGrid {(m_body.posX + Player::playerWidth - 1) / Constants::tileWidth};
    int posYBelowFeetGrid {(m_body.posY + Player::playerHeight) / Constants::tileHeight};

    // Basically is a loop that check every grid tile the player is inside (generally 2x2)
    for (int col {posXLeftGrid} ; col <= posXRightGrid ; ++col){
        if (map.tileAt(posYBelowFeetGrid, col) == element){
            return true;
        }
    }
    return false;
}

bool Player::hasEnteredLevel(){
    return m_enteredLevel;
}

Vector2 Player::getPosition(){
    return Vector2 {static_cast<float>(m_body.posX) + (Player::playerWidth / 2.0f), 
                    static_cast<float>(m_body.posY) + (Player::playerHeight / 2.0f)};
}

void Player::drawPlayer(){
    DrawRectangle(
        m_body.posX,
        m_body.posY,
        Constants::tileWidth, 
        Constants::tileHeight, 
        RED);
}