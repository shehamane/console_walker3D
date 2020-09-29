#ifndef CONSOLEWALKER3D_MINIMAP_H
#define CONSOLEWALKER3D_MINIMAP_H

#include "Player.h"
#include "Map.h"

class Minimap {
private:
    Player *player;
    Map *map;

public:
    Minimap(Map *m, Player *p);

    std::vector<std::string>* toFrame();
};

#endif //CONSOLEWALKER3D_MINIMAP_H
