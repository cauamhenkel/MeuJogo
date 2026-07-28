#ifndef MAP_H
#define MAP_H

#include "common.hpp"

template<typename T>
using vector2d = std::vector<std::vector<T>>;
using MapGrid = vector2d<char>;

class Map{
private:
    int m_horizontalTiles {};
    int m_verticalTiles {};
    MapGrid m_map {};
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

    const MapGrid& getTiles() const;
    const int getHorizontalTiles() const;
    const int getVerticalTiles() const;
};

void drawTile(int posX, int posY, Color color);

#endif