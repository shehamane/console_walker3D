#include "World.h"

World::World(Map *m, Player *p) {
    map = m;
    player = p;
}

std::vector<std::string>* World::toFrame() {
    auto *frame = new std::vector<std::string>(map->getHeight());

    for (int i = 0; i < map->getHeight(); ++i) {
        for (int j = 0; j < map->getWidth(); ++j)
            if ((int)player->getY() == i && (int)player->getX() == j)
                (*frame)[i] += 'P';
            else if (map->get(i, j))
                (*frame)[i] += '#';
            else
                (*frame)[i] += ' ';
        (*frame)[i] += '\n';
    }

    return frame;
}
