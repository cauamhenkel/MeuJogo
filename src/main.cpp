#include "my_game.hpp"
#include "map.hpp"

int main() {
    
    InitWindow(Constants::windowWidth, Constants::windowHeigth, "Jogao");
    SetTargetFPS(Constants::FPS);

    while(!WindowShouldClose()){
        
        BeginDrawing();

        ClearBackground(BLACK);
        DrawRectangle(300, 300, 10, 10, RED);
        
        EndDrawing();
    }
    
    CloseWindow();

    return 0;
}