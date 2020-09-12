#include "stage.h"
#include "common.h"

#include <time.h>
#include <ncurses.h>
#include <vector>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

Stage::Stage() {
    srand(time(NULL));

    getmaxyx(stdscr, maxY, maxX);
    floorNum = 0;

    for (int i = 0; i < STARTING_SIZE_Y; i++) {
        vector<char> _;
        floor.push_back(_);
        for (int j = 0; j < STARTING_SIZE_X; j++) {
            floor[i].push_back(' ');
        }
    }
    genFloor();
    Entity me(20, 3, '@');
    ents.push_back(me);
    player = ents.size()-1;
}

void Stage::spawnEnemy() {
    int y = (rand()%(floor.size()-2))+1;
    int x = floor[0].size()-2;
    Entity e(x, y, '$');
    ents.push_back(e);
}

void Stage::simEnt(int ent) {
    if (ent == player)
        return;

    int distance = abs(ents[player].x - ents[ent].x);
    int direction = ents[player].x - ents[ent].x;
    if (distance >= ents[ent].maxSpeed) {
        if (direction > 0) {
            ents[ent].x += ents[ent].maxSpeed;
        } else {
            ents[ent].x -= ents[ent].maxSpeed;
        }
    } else {
        if (direction > 0) {
            ents[ent].x += 1;
        } else {
            ents[ent].x -= 1;
        }
    }
}

int Stage::simulate() {
    vector<char> streetSpecial({'_', ','});
    for (int i = 1; i < floor.size()-1; i++) {
        floor[i][floor[i].size()-1] = '.';
        if (rand()%STREET_SPECIAL_PROB == 0) {
            floor[i][floor[i].size()-1] = streetSpecial[rand()%streetSpecial.size()];
        }
    }

    for (int i = 1; i < floor.size()-1; i++) {
        for (int j = 1; j < floor[i].size()-1; j++) {
            floor[i][j] = floor[i][j+1];
        }
    }
    for (int i = 1; i < floor.size()-1; i++) {
        floor[i][floor[i].size()-1] = '#';
    }

    if (rand()%ENEMY_PROB == 0) {
        spawnEnemy();
    }

    for (int i = 0; i < ents.size(); i++) {
        simEnt(i);
    }

    for (int i = 0; i < ents.size(); i++) {
        if (player == i)
            continue;

        if (ents[player].x == ents[i].x && ents[player].y == ents[i].y) {
            return Encounter;
        }
    }

    

    return Normal;
}

void Stage::render() {
    for (int i = 0; i < floor.size(); i++) {
        for (int j = 0; j < floor[i].size(); j++) {
            mvprintw(VPAD + i, HPAD + j, "%c", floor[i][j]);
        }
    }

    for (int i = 0; i < ents.size(); i++) {
        mvprintw(VPAD + ents[i].y, HPAD + ents[i].x, "%c", ents[i].sym);
    }

    mvprintw(VPAD + ents[player].y, HPAD + ents[player].x, "@");
}

void Stage::genFloor() {
    for (int i = 0; i < floor.size(); i++) {
        for (int j = 0; j < floor[i].size(); j++) {
            floor[i][j] = '.';
            if (i == 0) {
                floor[i][j] = '#';
            }
            if (i == floor.size()-1) {
                floor[i][j] = '#';
            }
            if (j == 0) {
                floor[i][j] = '#';
            }
            if (j == floor[i].size()-1) {
                floor[i][j] = '#';
            }
        }
    }

}
