#ifndef CONSOLEWALKER3D_WORLD_H
#define CONSOLEWALKER3D_WORLD_H

#include "Player.h"
#include "Map.h"
#include "Frame.h"

class World {
private:
    Player *player;
    Map *map;
    Frame *frame;

public:
    World(Map *m, Player *p, Frame *f);

    void toFrame();
    void update();
};

#endif //CONSOLEWALKER3D_WORLD_H
