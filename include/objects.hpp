#ifndef OBJECTS_H
#define OBJECTS_H

#include "common.hpp"
#include "entity.hpp"
#include "map.hpp"
#include "player.hpp"

struct Game{
    Player player {};
    Map map{};
    GameState gameState {GameState::MainMenu};
    MenusSelection menusSelections {};
    Camera2D camera {};
};

#endif