#pragma once

#include <vector>

class Entity {
public:
    int health;
    int damage;
    std::vector<Entity> inv;
    int x, y;
    char sym;                     
    int maxSpeed;

    Entity(int _x, int _y, char sym);
};
