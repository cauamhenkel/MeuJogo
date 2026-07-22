#include "my_game.hpp"

template <typename T, std::size_t Row, std::size_t Col>
using Array2d = std::array<std::array<T, Col>, Row>;

class Map{
private:
    Array2d<char, Constants::tiles, Constants::tiles> m_map {};
    RenderTexture2D m_mapImage {};

public:
    ~Map() {
        // unload the texture when the program terminates
        if (m_mapImage.id > 0) UnloadRenderTexture(m_mapImage);
    }

    // create the array of the map
    void createMap();
    // draw all the tiles of the map
    void drawImageMap();
    // create a single texture for the map
    void createImageMap();
    // draw the map
    void drawMap();
};

void drawTile(int posX, int posY, Color color);