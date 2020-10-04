#include <string>
#include "Frame.h"


Frame::Frame(int w, int h) : chars(h) {
    width = w;
    height = h;
}

void Frame::change(int x, int y, char c) {
    chars[y][x] = c;
}

Frame::Frame(Map *map):chars(map->getHeight()) {
    this->map = map;
    for (int i = 0; i<chars.size(); ++i) {
        for (int j = 0; j < map->getWidth(); ++j)
            chars[i] += map->get(j, i) ? '#' : ' ';
        chars[i] += '\n';
    }
}

void Frame::update() {
    for (int i = 0; i<chars.size(); ++i) {
        for (int j = 0; j < map->getWidth(); ++j)
            chars[i][j] = map->get(j, i) ? '#' : ' ';
        chars[i][map->getWidth()] = '\n';
    }
}


