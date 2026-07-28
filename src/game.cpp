#include "game.hpp"

void initializeCamera(Camera2D& camera){
    camera.offset = Vector2{static_cast<float>(Constants::windowWidth/2), static_cast<float>(Constants::windowHeight/2)};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f; 
}

void getCameraPosition(Game& game){
    Vector2 targetPos = game.player.getPosition();
    
    int mapWidthPixels {game.map.getHorizontalTiles() * Constants::tileWidth};
    int mapHeightPixels {game.map.getVerticalTiles() * Constants::tileHeight};

    // 2. Tamanho visível da tela no mundo (considerando o zoom)
    float halfScreenWidth  = static_cast<float>(Constants::windowWidth/2) / game.camera.zoom;
    float halfScreenHeight = static_cast<float>(Constants::windowHeight/2) / game.camera.zoom;

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
    if (mapWidthPixels < GetScreenWidth()) {
        targetPos.x = mapWidthPixels / 2.0f;
    }
    if (mapHeightPixels < GetScreenHeight()) {
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

        case GameState::InGame:
            if (IsKeyPressed(KEY_TAB)){
                game.gameState = GameState::Paused;
                game.menusSelections.pauseSelection = PauseSelection::Continue;
            }
            game.player.updatePlayer(game.map);

            getCameraPosition(game);
            break;

        case GameState::Paused:
            pausedMenuHandling(game);
            break;

        case GameState::Victory:
            break;

        case GameState::Defeat:
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
            break;

        case GameState::Defeat:
            break;
        }

    EndDrawing();
}