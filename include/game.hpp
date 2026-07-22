#ifndef GAME_HPP
#define GAME_HPP

#include <array>
#include <string>
#include <string_view>
#include <iostream>
#include <vector>

#include "raylib.h"

namespace Constants{
    inline constexpr int FPS {60};
    inline constexpr int tiles {30};

    inline constexpr int tileWidth {20};
    inline constexpr int tileHeigth {20};

    inline constexpr int windowWidth {tileWidth * tiles};
    inline constexpr int windowHeigth {tileHeigth * tiles};
}

#endif