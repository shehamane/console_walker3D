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
    for (int i = 0; i<chars.size(); ++i) {
        for (int j = 0; j < map->getWidth(); ++j)
            chars[i] += map->get(j, i) ? '#' : ' ';
        chars[i] += '\n';
    }
}


