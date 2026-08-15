#include "map.hpp"

void Map::createMap() {
    {
        std::ifstream configFile {std::format("../assets/levels/config/map_{}_config.txt", getLevel())};
        char trash {};
        configFile >> m_horizontalTiles >> trash >> m_verticalTiles;
    }

    {
        std::ifstream designFile {std::format("../assets/levels/design/map_{}.txt", getLevel())};
    }
    
    m_map = {
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ','E',' ',' ',' ',' ',' ',' ','F',' ',' ',' ',' ',' ',' ','H',' ',' ',' ','E',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ','Z','Z','Z','Z','Z','Z','Z','Z','Z','Z','Z','Z','Z','Z','Z','X','Z','Z','Z','Z','Z','Z',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','H',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','H',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','H',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','H',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','H',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','H',' ',' ',' ',' ',' ',' ','H',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ','Z','Z','Z','Z','Z','Z','X','Z','Z','Z','Z','Z','Z','Z','Z','Z','Z','Z','Z','Z','Z',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','H',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','H',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','H',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','H',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','H',' ','E','H',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','Z','Z','Z','Z','Z','Z','X','Z','Z','Z','Z',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','H',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','H',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','H',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ','H',' ',' ',' ',' ',' ',' ',' ','H',' ',' ',' ',' ',' ',' ',' ','H',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ','Z','X','Z','Z','Z','Z','Z','Z','Z','Z','Z','Z','Z','Z','Z','Z','Z','X','Z','Z','Z',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ','H',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','H',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ','H',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','H',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ','H',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','H',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ','H',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','H',' ',' ',' ',' ',' '},
        {' ','E',' ',' ',' ',' ',' ',' ','H',' ',' ',' ',' ','P',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','H',' ',' ',' ',' ',' '},
        {'Z','Z','Z','Z','Z','Z','Z','Z','Z','Z','Z','Z','Z','Z','Z','Z','Z','Z','Z','Z','Z','Z','Z','Z','Z','Z','Z','Z','Z','Z'}
    };
}

void Map::goToNextLevel(){
    ++m_level;
}

void Map::drawImageMap(){
    Color color {};
    for (std::size_t row {0} ; row < static_cast<size_t>(m_verticalTiles) ; ++row){
        for (std::size_t col {0} ; col < static_cast<size_t>(m_horizontalTiles) ; ++col){
            switch (m_map[row][col]){
            case 'Z':
                color = BROWN;
                break;
            case 'H':
            case 'X':
                color = YELLOW;
                break;
            case 'F':
                color = PURPLE;
                break;
            default:
                color = BLANK;
            }

            DrawRectangle(
                    col * Constants::tileWidth, 
                    row * Constants::tileHeight, 
                    Constants::tileWidth, 
                    Constants::tileHeight, 
                    color);
        }
    }
}
// auxiliar function
void drawTile(int posX, int posY, Color color){
    DrawRectangle(
        posX * Constants::tileWidth, 
        posY * Constants::tileHeight, 
        Constants::tileWidth, 
        Constants::tileHeight, 
        color);
}

void Map::createImageMap(){
    if (m_mapImage.id > 0) {
        UnloadRenderTexture(m_mapImage);
    }
    
    m_mapImage = LoadRenderTexture(m_horizontalTiles * Constants::tileWidth, m_verticalTiles * Constants::tileHeight);

    BeginTextureMode(m_mapImage);

    ClearBackground(BLANK);
    drawImageMap(); 
    
    EndTextureMode();
}

void Map::drawMap(){
    DrawTextureRec(
        m_mapImage.texture, 
        Rectangle{0, 0, (float)m_mapImage.texture.width, (float)-m_mapImage.texture.height}, 
        Vector2{0, 0}, 
        WHITE);
}

const int Map::getLevel() const{
    return m_level;
}

const MapGrid& Map::getTiles() const{
    return m_map;
}

const char Map::tileAt(int row, int col) const {
    if (row < 0 || row >= m_verticalTiles || col < 0 || col >= m_horizontalTiles) 
    // if the player is out of bounds, return air
        return Elements::air; 
    return m_map[row][col];
}

const int Map::getHorizontalTiles() const{
    return m_horizontalTiles;
}

const int Map::getVerticalTiles() const{
    return m_verticalTiles;
}