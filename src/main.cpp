#include "game.hpp"
#include "map.hpp"
#include "player.hpp"
#include "menus.hpp"

int main() {
    
    InitWindow(Constants::windowWidth, Constants::windowHeight, "Jogao");
    SetTargetFPS(Constants::FPS);

    Map map {};
    map.createMap();
    map.createImageMap();

    Player player {};
    player.placeInMap(map);

    GameState gameState {GameState::InGame};
    MenusSelection menusSelection {};

    while(!WindowShouldClose()){
        switch (gameState){
        case GameState::MainMenu:
            mainMenuHandling(gameState);
            break;

        case GameState::InGame:
            updatePlayer(player);
            break;

        case GameState::Paused:
            break;

        case GameState::Victory:
            break;

        case GameState::Defeat:
            break;
        }

        BeginDrawing();
        
        switch (gameState){
        case GameState::MainMenu:
            drawMainMenu();
            break;

        case GameState::InGame:
            ClearBackground(BLACK);
            map.drawMap();
            player.drawPlayer();
            break;

        case GameState::Paused:
            break;

        case GameState::Victory:
            break;

        case GameState::Defeat:
            break;
        }

        EndDrawing();

    }
    
    CloseWindow();

    return 0;
}