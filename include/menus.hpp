#include "game.hpp"

namespace Formatting{
    inline constexpr int mainMenuButtonFontSize {40};
}

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
};

void mainMenuHandling(GameState& gameState);

void drawMainMenu();

void drawButton(const char* text, int fontSize, int posX, int posY, int width, int height, 
                Color innerColor, Color edgeColor);