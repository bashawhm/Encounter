#include "entity.h"

Entity::Entity(int _x, int _y, char _sym) {
    health = 30;
    damage = 10;
    x = _x;
    y = _y;
    sym = _sym;
    maxSpeed = 2;
}
