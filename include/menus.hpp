#include "common.hpp"
#include "objects.hpp"

namespace Formatting{
    inline constexpr int titleFontSize {Constants::tileHeight * 3};
    inline constexpr int titleTextEdge {static_cast<int>(Constants::tileWidth * 0.2)};

    inline constexpr int buttonWidth {static_cast<int>(Constants::tileWidth * 7)};
    inline constexpr int buttonHeight {static_cast<int>(Constants::tileHeight * 2.5)};
    inline constexpr int buttonFontSize {static_cast<int>(Constants::tileHeight * 1.3)};
    inline constexpr int buttonTextEdge {static_cast<int>(Constants::tileWidth * 0.1)};

    inline constexpr Color buttonInnerColor {GRAY};
    inline constexpr Color selectedButtonInnerColor {LIGHTGRAY};
    inline constexpr Color buttonEdgeColor {BLACK};

    inline constexpr Color textColor {PURPLE};
    inline constexpr Color textEdgeColor {BLACK};

    inline constexpr int buttonPosX {(Constants::windowWidth/2) - (buttonWidth/2)};
    inline constexpr int button1PosY {Constants::tileHeight * 12};
    inline constexpr int button2PosY {button1PosY + Constants::tileHeight * 4};
    inline constexpr int button3PosY {button2PosY + Constants::tileHeight * 4};
}

void mainMenuHandling(Game& game);
void pausedMenuHandling(Game& game);
void victoryMenuHandling(Game& game);

void drawMainMenu(const MenusSelection& selection);
void drawPausedMenu(const MenusSelection& selection);
void drawVictoryMenu();

void drawTitle();

void drawButtonMenu(const char* text, int posY, Color innerColor);
void drawButton(const char* text, int fontSize, int posX, int posY, int width, int height, 
                Color innerColor, Color edgeColor);

void drawTextWithEdge(const char* text, int fontSize, int edgeSize, int posY, Color innerColor, Color edgeColor);

MainMenuSelection operator++(MainMenuSelection& selection);
MainMenuSelection operator--(MainMenuSelection& selection);
PauseSelection operator++(PauseSelection& selection);
PauseSelection operator--(PauseSelection& selection);