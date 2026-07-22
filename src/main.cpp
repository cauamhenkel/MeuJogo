#include "game.hpp"
#include "map.hpp"
#include "player.hpp"

int main() {
    
    InitWindow(Constants::windowWidth, Constants::windowHeigth, "Jogao");
    SetTargetFPS(Constants::FPS);

    Map map {};
    map.createMap();
    map.createImageMap();

    Player player {};
    player.placeInMap(map);

    while(!WindowShouldClose()){
        
        updatePlayer(player);

        BeginDrawing();

        ClearBackground(BLACK);
        
        map.drawMap();
        player.drawPlayer();

        EndDrawing();

    }
    
    CloseWindow();

    return 0;
}