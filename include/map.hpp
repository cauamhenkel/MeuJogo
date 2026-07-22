#include "my_game.hpp"

template <typename T, std::size_t Row, std::size_t Col>
using Array2d = std::array<std::array<T, Col>, Row>;

class Map{
private:
    Array2d<char, Constants::tiles, Constants::tiles> m_map {};

public:
    void createMap();
    void drawMap();
};

void drawTile(int posX, int posY, Color color);