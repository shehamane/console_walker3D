#ifndef CONSOLEWALKER3D_WORLD_H
#define CONSOLEWALKER3D_WORLD_H

#include "Player.h"
#include "Map.h"

class World {
private:
    Player *player;
    Map *map;

public:
    World(Map *m, Player *p);

    std::vector<std::string>* toFrame();
};

#endif //CONSOLEWALKER3D_WORLD_H
