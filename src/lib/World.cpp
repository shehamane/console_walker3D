#include "World.h"

World::World(Map *m, Player *p, Frame *f) {
    map = m;
    player = p;
    frame = f;
}

void World::toFrame() {
    for (int i = 0; i < map->getHeight(); ++i) {
        for (int j = 0; j < map->getWidth(); ++j)
            if ((int)player->getY() == i && (int)player->getX() == j)
                frame->change(j, i, 'P');
            else if (map->get(j, i))
                frame->change(j, i, '#');
            else
                frame->change(j, i, ' ');
        frame->change(i, map->getWidth()+1, '\n');
    }
}

void World::update() {
    frame->change(player->getX(), player->getY(), 'P');
}
