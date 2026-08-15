#ifndef GAME_H
#define GAME_H

#include "objects.hpp"
#include "menus.hpp"

void initializeCamera(Camera2D& camera);
void getCameraPosition(Game& game);

void processGame(Game& game);
void drawGame(Game& game);

bool playerWon(const Map& map);

#endif