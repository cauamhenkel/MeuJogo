#include "menus.hpp"

void mainMenuHandling(GameState& gameState){

}

void drawMainMenu(){
    ClearBackground(BLACK);

    //drawButton();

}

void drawButton(const char* text, int fontSize, int posX, int posY, int width, int height, 
                Color innerColor, Color edgeColor){
    DrawRectangle(posX, posY, width, height, innerColor);

    DrawRectangle((posX - Constants::tileWidth/4), (posY - Constants::tileWidth/4), 
                 (width + Constants::tileWidth/2), (height + Constants::tileHeight/2), edgeColor);
}

void drawTextWithEdge(const char* text){

}