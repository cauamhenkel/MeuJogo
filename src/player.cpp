#include "player.hpp"

/* Class functions */

void Player::updatePlayer(Map& map){
    if (IsKeyPressed(KEY_W) && onStairs(map)){
        m_body.state = EntityState::InStairs;
        centralizePlayerOnStairs(map);
    }
    
    if (m_body.state == EntityState::InGround || m_body.state == EntityState::InAir){
        updatePositionX();
    }
    
    if (m_body.state == EntityState::InStairs){
        processPlayerOnStairs();
    }
}

void Player::placeInMap(const Map& map){
    const MapGrid& mapGrid = map.getTiles();

    for (size_t row {0} ; row < Constants::tiles ; ++row){
        for (size_t col {0} ; col < Constants::tiles ; ++col){
            if (mapGrid[row][col] == 'P'){
                m_body.posX = col * Constants::tileWidth;
                m_body.posY = row * Constants::tileHeight;
            }
        }
    }
}

void Player::setMaxHealth(){
    m_health = Player::maxHealth;
}

bool Player::onElement(Map& map, const char element){
    int posXLeftGrid {(m_body.posX) / Constants::tileWidth};
    int posXRightGrid {(m_body.posX + Constants::tileWidth - 1) / Constants::tileWidth};
    int posYHeadGrid {(m_body.posY) / Constants::tileHeight};
    int posYFeetGrid {(m_body.posY + Constants::tileHeight - 1) / Constants::tileHeight};

    const MapGrid& grid {map.getTiles()};

    // Basically is a loop that check every grid tile the player is inside (generally 2x2)

    for (int row {posYHeadGrid} ; row <= posYFeetGrid ; ++row){
        for (int col {posXLeftGrid} ; col <= posXRightGrid ; ++col){
            if (grid[row][col] == element){
                return true;
            }
        }
    }
    return false;
}

bool Player::onStairs(Map& map){
    return (onElement(map, Elements::climb) || onElement(map, Elements::stair) || onElement(map, Elements::descent));
}

void Player::centralizePlayerOnStairs(Map& map){
    int posXLeftGrid {(m_body.posX) / Constants::tileWidth};
    int posXRightGrid {(m_body.posX + Constants::tileWidth - 1) / Constants::tileWidth};
    int posYGrid {(m_body.posY) / Constants::tileHeight};

    const MapGrid& grid {map.getTiles()};

    char farLeft {grid[posYGrid][posXLeftGrid]};

    if ((farLeft == Elements::climb) || (farLeft == Elements::stair) || (farLeft == Elements::descent)){
        m_body.posX -= (m_body.posX % Constants::tileWidth);
    }
    else{
        m_body.posX -= (m_body.posX % Constants::tileWidth);
        m_body.posX += Constants::tileWidth;
    }
}

void Player::processPlayerOnStairs(){

}

void Player::updatePositionX(){
    if (((m_body.posX + Constants::tileWidth) < Constants::windowWidth) && IsKeyDown(KEY_D)){
        m_body.movePosX(m_body.velX, Direction::Right);
    }
    if ((m_body.posX) > 0 && IsKeyDown(KEY_A)){
        m_body.movePosX(m_body.velX, Direction::Left);
    }
}

void Player::drawPlayer(){
    DrawRectangle(
        m_body.posX,
        m_body.posY,
        Constants::tileWidth, 
        Constants::tileHeight, 
        RED);
}