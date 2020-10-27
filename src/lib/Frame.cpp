#include "Frame.h"
#include "colors.h"


Frame::Frame(int w, int h, Map *m) : pixels(h, std::vector<unsigned char>(w)) {
    width = w;
    height = h;
    map = m;
    for (int i = 0; i < m->getHeight(); ++i)
        for (int j = 0; j < m->getWidth(); ++j)
            pixels[i][j + m->getWidth()] = m->get(j, i) ? B_BLUE : B_BLACK;
}

Frame::Frame(Map *map) : pixels(map->getHeight(), std::vector<unsigned char>(map->getWidth())) {
    this->map = map;
    width = map->getWidth();
    height = map->getHeight();
    for (int i = 0; i < height; ++i)
        for (int j = 0; j < width; ++j)
            pixels[i][j] = map->get(j, i) ? B_BLUE : B_BLACK;
}

void Frame::update() {
    for (int i = 0; i < height; ++i)
        for (int j = 0; j < width; ++j)
            pixels[i][j] = map->get(j, i) ? B_BLUE : B_BLACK;
}

void Frame::change(int x, int y, unsigned char c) {
    pixels[y][x] = c;
}

void Frame::drawRect(int x, int h, int angle, int color) {
    int w = (width - map->getWidth())/angle;
    x*=w;
    for (int i = 0; i<w; ++i)
        drawColumn(x+i, h, color);
}

void Frame::drawColumn(int x, int h, int color) {
    if (h > height)
        h = height;
    int start = (height - h) / 2;
    int end = height - 1 - (height - h) / 2;
    for (int i = start; i <= end; ++i)
        pixels[i][x] = color;
}

void Frame::erase() {
    for (int i = 0; i < height; ++i)
        for (int j = 0; j < width- map->getWidth(); ++j)
            pixels[i][j] = 0;
}


