#include "player.hpp"

/* Class functions */

void Player::placeInMap(const Map& map){
    const MapGrid& mapGrid = map.getTiles();

    for (size_t row {0} ; row < Constants::tiles ; ++row){
        for (size_t col {0} ; col < Constants::tiles ; ++col){
            if (mapGrid[row][col] == 'P'){
                m_body.posX = col * Constants::tileWidth;
                m_body.posY = row * Constants::tileHeigth;
            }
        }
    }
}

void Player::drawPlayer(){
    DrawRectangle(
        m_body.posX,
        m_body.posY,
        Constants::tileWidth, 
        Constants::tileHeigth, 
        RED);
}

void Player::updatePositionX(){
    if (((m_body.posX + Constants::tileWidth) < Constants::windowWidth) && IsKeyDown(KEY_D)){
        m_body.movePosX(m_body.velX, Direction::Right);
    }
    if ((m_body.posX) > 0 && IsKeyDown(KEY_A)){
        m_body.movePosX(m_body.velX, Direction::Left);
    }
}

/* General functions */

void updatePlayer(Player& player){
    player.updatePositionX();
}