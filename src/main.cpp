#include "game.hpp"

int main() {
    Game game {};

    InitWindow(Constants::windowWidth, Constants::windowHeight, "Jogao");
    SetTargetFPS(Constants::FPS);
    HideCursor();

    initializeCamera(game.camera);

    while(!WindowShouldClose() && !(game.menusSelections.exitGame)){
        processGame(game);
        
        drawGame(game);
    }
    
    CloseWindow();
    
    return 0;
}