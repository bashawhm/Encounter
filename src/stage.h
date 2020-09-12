#pragma once

#include <vector>
#include "entity.h"

class Stage {
public:
    int maxX;
    int maxY;
    int floorNum;
    std::vector<std::vector<char>> floor;
    std::vector<Entity> ents;
    int player;


    Stage();
    int simulate();
    void render();
    void genFloor();
    void spawnEnemy();
    void simEnt(int ent);
};
