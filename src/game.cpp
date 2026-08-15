#include "game.hpp"

void initializeCamera(Camera2D& camera){
    camera.offset = Vector2{static_cast<float>(Constants::windowWidth/2.0f), static_cast<float>(Constants::windowHeight/2.0f)};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f; 
}

void getCameraPosition(Game& game){
    Vector2 targetPos = game.player.getPosition();
    
    int mapWidthPixels {game.map.getHorizontalTiles() * Constants::tileWidth};
    int mapHeightPixels {game.map.getVerticalTiles() * Constants::tileHeight};

    // 2. Tamanho visível da tela no mundo (considerando o zoom)
    float halfScreenWidth  = static_cast<float>(Constants::windowWidth/2.0f) / game.camera.zoom;
    float halfScreenHeight = static_cast<float>(Constants::windowHeight/2.0f) / game.camera.zoom;

    // 3. Aplica os limites (Clamp) para a câmera não sair do mapa
    
    // Limites no eixo X
    float minX = halfScreenWidth;
    float maxX = mapWidthPixels - halfScreenWidth;
    targetPos.x = std::clamp(targetPos.x, minX, maxX);

    // Limites no eixo Y
    float minY = halfScreenHeight;
    float maxY = mapHeightPixels - halfScreenHeight;
    targetPos.y = std::clamp(targetPos.y, minY, maxY);

    // 4. Se o mapa for MENOR que a própria tela, trava no centro do mapa
    if (mapWidthPixels < (2 * halfScreenWidth)) {
        targetPos.x = mapWidthPixels / 2.0f;
    }
    if (mapHeightPixels < (2 * halfScreenHeight)) {
        targetPos.y = mapHeightPixels / 2.0f;
    }

    // 5. Atribui a posição limitada à câmera
    game.camera.target = targetPos;
}

void processGame(Game& game){
    switch (game.gameState){
    case GameState::MainMenu:
        mainMenuHandling(game);
        break;

    case GameState::Paused:
        pausedMenuHandling(game);
        break;

    case GameState::Victory:
        victoryMenuHandling(game);
        break;

    case GameState::Defeat:
        break;
    case GameState::InGame:
        // Runs only one time, rigth after entering the level
        if (game.player.hasEnteredLevel()){
            if (playerWon(game.map)){
                game.gameState = GameState::Victory;
            }
            else{
                game.map.createMap();
                game.map.createImageMap();

                game.player.placeInMap(game.map);
                game.player.resetPlayer();
            }

            game.player.setEnteredLevel(false);
        }
        if(game.gameState == GameState::InGame){
            if (IsKeyPressed(KEY_TAB)){
                game.gameState = GameState::Paused;
                game.menusSelections.pauseSelection = PauseSelection::Continue;
            }
            game.player.updatePlayer(game.map);

            getCameraPosition(game);
        }
        break;
    }
}

void drawGame(Game& game){
    BeginDrawing();
    switch (game.gameState){
    case GameState::MainMenu:
        drawMainMenu(game.menusSelections);
        break;

    case GameState::InGame:
        ClearBackground(BLACK);
        BeginMode2D(game.camera);
            
        game.map.drawMap();
        game.player.drawPlayer();
            
        EndMode2D();
        break;

    case GameState::Paused:
        drawPausedMenu(game.menusSelections);
        break;

    case GameState::Victory:
        drawVictoryMenu();
        break;

    case GameState::Defeat:
        break;
    }

    EndDrawing();
}

bool playerWon(const Map& map){
    std::string LevelConfigName {std::format("../assets/levels/config/map_{}_config.txt", map.getLevel())};
    std::ifstream successOpenLevelConfig {LevelConfigName};

    std::string LevelDesignName {std::format("../assets/levels/design/map_{}.txt", map.getLevel())};
    std::ifstream successOpenLevelDesign {LevelDesignName};

    // if the player plays all the levels and enter the last crystal, 
    // the level will become a number that does not exist in the existing files, granting the victory
    if (!successOpenLevelConfig || !successOpenLevelDesign){
        return true;
    }
    else{
        return false;
    }
}