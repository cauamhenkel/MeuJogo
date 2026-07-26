#include "menus.hpp"

void mainMenuHandling(Player& player, Map& map, GameState& gameState, MenusSelection& selection){
    if (IsKeyPressed(KEY_DOWN)){
        ++(selection.mainMenuSelection);
    }
    if (IsKeyPressed(KEY_UP)){
        --(selection.mainMenuSelection);
    }

    switch(selection.mainMenuSelection){
        case MainMenuSelection::Play:
            if (IsKeyPressed(KEY_ENTER)){
                gameState = GameState::InGame;
                
                map.createMap();
                map.createImageMap();

                player.placeInMap(map);
                player.setMaxHealth();
            }
            break;
        case MainMenuSelection::Continue:
            break;
        case MainMenuSelection::Exit:
            if (IsKeyPressed(KEY_ENTER)){
                selection.exitGame = true;
            }
    }
}

void pausedMenuHandling(GameState& gameState, MenusSelection& selection){
    if (IsKeyPressed(KEY_DOWN)){
        ++(selection.pauseSelection);
    }
    if (IsKeyPressed(KEY_UP)){
        --(selection.pauseSelection);
    }

    switch(selection.pauseSelection){
        case PauseSelection::Continue:
            if (IsKeyPressed(KEY_ENTER)){
                gameState = GameState::InGame;
            }
            break;
        case PauseSelection::MainMenu:
            if (IsKeyPressed(KEY_ENTER)){
                gameState = GameState::MainMenu;
            }
            break;
        case PauseSelection::Exit:
            if (IsKeyPressed(KEY_ENTER)){
                selection.exitGame = true;
            }
    }
}

void drawMainMenu(const MenusSelection& selection){
    ClearBackground(DARKGRAY);

    drawTitle();

    const char* button1Text {"Play"};
    const char* button2Text {"Continue"};
    const char* button3Text {"Exit"};
    drawButtonMenu(button1Text, Formatting::button1PosY, (selection.mainMenuSelection == MainMenuSelection::Play) 
                       ? Formatting::selectedButtonInnerColor : Formatting::buttonInnerColor);
    drawButtonMenu(button2Text, Formatting::button2PosY, (selection.mainMenuSelection == MainMenuSelection::Continue) 
                       ? Formatting::selectedButtonInnerColor : Formatting::buttonInnerColor);
    drawButtonMenu(button3Text, Formatting::button3PosY, (selection.mainMenuSelection == MainMenuSelection::Exit) 
                       ? Formatting::selectedButtonInnerColor : Formatting::buttonInnerColor);

}

void drawPausedMenu(const MenusSelection& selection){
    ClearBackground(DARKGRAY);

    const char* button1Text {"Continue"};
    const char* button2Text {"Main menu"};
    const char* button3Text {"Exit"};
    drawButtonMenu(button1Text, Formatting::button1PosY, (selection.pauseSelection == PauseSelection::Continue) 
                       ? Formatting::selectedButtonInnerColor : Formatting::buttonInnerColor);
    drawButtonMenu(button2Text, Formatting::button2PosY, (selection.pauseSelection == PauseSelection::MainMenu) 
                       ? Formatting::selectedButtonInnerColor : Formatting::buttonInnerColor);
    drawButtonMenu(button3Text, Formatting::button3PosY, (selection.pauseSelection == PauseSelection::Exit) 
                       ? Formatting::selectedButtonInnerColor : Formatting::buttonInnerColor);
}

void drawTitle(){
    const char* titleLine1 {"El Cowboy"};
    const char* titleLine2 {"Emiliano 2"};
    drawTextWithEdge(titleLine1, Formatting::titleFontSize, Formatting::titleTextEdge, 
                     Constants::tileHeight * 2, Formatting::textColor, Formatting::textEdgeColor);
    drawTextWithEdge(titleLine2, Formatting::titleFontSize * 1.2, Formatting::titleTextEdge, 
                     (Constants::tileHeight * 2) + (Formatting::titleFontSize * 1.2), Formatting::textColor, Formatting::textEdgeColor);
}

void drawButtonMenu(const char* text, int posY, Color innerColor){
    drawButton(text, Formatting::buttonFontSize, Formatting::buttonPosX, 
               posY, Formatting::buttonWidth, Formatting::buttonHeight, innerColor, Formatting::buttonEdgeColor);
}

void drawButton(const char* text, int fontSize, int posX, int posY, int width, int height, 
                Color innerColor, Color edgeColor){

    DrawRectangle((posX - Constants::tileWidth/4), (posY - Constants::tileWidth/4), 
                 (width + Constants::tileWidth/2), (height + Constants::tileHeight/2), edgeColor);

    DrawRectangle(posX, posY, width, height, innerColor);

    drawTextWithEdge(text, fontSize, Formatting::buttonTextEdge, (posY + (height/2) - (fontSize/2)), 
                     Formatting::textColor, Formatting::textEdgeColor);
}

void drawTextWithEdge(const char* text, int fontSize, int edgeSize, int posY, Color innerColor, Color edgeColor){
    DrawText(text, ((Constants::windowWidth/2) - (MeasureText(text, fontSize)/2) + edgeSize), posY, fontSize, edgeColor);
    DrawText(text, ((Constants::windowWidth/2) - (MeasureText(text, fontSize)/2) - edgeSize), posY, fontSize, edgeColor);
    DrawText(text, (Constants::windowWidth/2) - (MeasureText(text, fontSize)/2), posY + edgeSize, fontSize, edgeColor);
    DrawText(text, (Constants::windowWidth/2) - (MeasureText(text, fontSize)/2), posY - edgeSize, fontSize, edgeColor);

    DrawText(text, (Constants::windowWidth/2) - (MeasureText(text, fontSize)/2), posY, fontSize, innerColor);
}

MainMenuSelection operator++(MainMenuSelection& selection){
    if (selection == MainMenuSelection::Exit){
        selection = MainMenuSelection::Play;
    }
    else{
        selection = static_cast<MainMenuSelection>(static_cast<int>(selection)+1);
    }
    return selection;
}

MainMenuSelection operator--(MainMenuSelection& selection){
    if (selection == MainMenuSelection::Play){
        selection = MainMenuSelection::Exit;
    }
    else{
        selection = static_cast<MainMenuSelection>(static_cast<int>(selection)-1);
    }
    return selection;
}

PauseSelection operator++(PauseSelection& selection){
    if (selection == PauseSelection::Exit){
        selection = PauseSelection::Continue;
    }
    else{
        selection = static_cast<PauseSelection>(static_cast<int>(selection)+1);
    }
    return selection;
}

PauseSelection operator--(PauseSelection& selection){
    if (selection == PauseSelection::Continue){
        selection = PauseSelection::Exit;
    }
    else{
        selection = static_cast<PauseSelection>(static_cast<int>(selection)-1);
    }
    return selection;
}