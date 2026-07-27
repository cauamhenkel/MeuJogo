#ifndef GAME_HPP
#define GAME_HPP

#include <array>
#include <string>
#include <string_view>
#include <iostream>
#include <vector>

#include "raylib.h"

enum class GameState{
    MainMenu,
    InGame,
    Paused,
    Victory,
    Defeat
};

namespace Constants{
    inline constexpr int FPS {60};
    inline constexpr int tiles {30};

    inline constexpr int tileWidth {20};
    inline constexpr int tileHeight {20};

    inline constexpr int windowWidth {tileWidth * tiles};
    inline constexpr int windowHeight {tileHeight * tiles};
}

namespace Elements{
    inline constexpr char air {' '};
    inline constexpr char ground {'Z'};
    inline constexpr char climb {'S'};
    inline constexpr char stair {'H'};
    inline constexpr char descent {'Z'};
    inline constexpr char platform {'X'};
    inline constexpr char crystal {'F'};
}

#endif