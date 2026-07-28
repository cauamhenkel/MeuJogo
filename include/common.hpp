#ifndef COMMON_HPP
#define COMMON_HPP

#include <algorithm>
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

enum class MainMenuSelection{
    Play,
    Continue,
    Exit
};

enum class PauseSelection{
    Continue,
    MainMenu,
    Exit
};

struct MenusSelection{
    MainMenuSelection mainMenuSelection {MainMenuSelection::Play};
    PauseSelection pauseSelection {PauseSelection::Continue};
    bool exitGame {false};
};

namespace Constants{
    inline constexpr int FPS {60};
    inline constexpr int horizontalTilesOnScreen {25};
    inline constexpr int verticalTilesOnScreen {25};

    inline constexpr int tileWidth {25};
    inline constexpr int tileHeight {25};

    inline constexpr int windowWidth {tileWidth * horizontalTilesOnScreen};
    inline constexpr int windowHeight {tileHeight * verticalTilesOnScreen};
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