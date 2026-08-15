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

/*
Coisas pra fazer:

adicionar teste se chegou no F e passar de fase
- incrementar level
- criar novo mapa (com novo level de referencia)

arrumar bug bizarro nas escadas

*/