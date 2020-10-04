#include <string>
#include "Frame.h"
#include "colors.h"


Frame::Frame(int w, int h) : pixels(h, std::vector<unsigned char>(w)) {
    width = w;
    height = h;
}

Frame::Frame(Map *map):pixels(map->getHeight(), std::vector<unsigned char>(map->getWidth())) {
    this->map = map;
    width = map->getWidth();
    height = map->getHeight();
    for (int i = 0; i<height; ++i)
        for (int j = 0; j<width; ++j)
            pixels[i][j] = map->get(j, i) ? B_WHITE : B_BLACK;
}

void Frame::update() {
    for (int i = 0; i<height; ++i)
        for (int j = 0; j<width; ++j)
            pixels[i][j] = map->get(j, i) ? B_WHITE : B_BLACK;
}

void Frame::change(int x, int y, unsigned char c) {
    pixels[y][x] = c;
}


