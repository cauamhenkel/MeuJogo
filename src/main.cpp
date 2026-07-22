#include "my_game.hpp"
#include "map.hpp"

int main() {
    
    InitWindow(Constants::windowWidth, Constants::windowHeigth, "Jogao");
    SetTargetFPS(Constants::FPS);

    Map map {};
    map.createMap();
    map.createImageMap();

    while(!WindowShouldClose()){
        
        BeginDrawing();

        ClearBackground(BLACK);
        map.drawMap();
        
        EndDrawing();
    }
    
    CloseWindow();

    return 0;
}