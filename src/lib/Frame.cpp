#include "Frame.h"
#include "colors.h"

Frame::Frame(int w, int h, Map *m) : pixels(h, std::vector<unsigned char>(w)) {
    width = w;
    height = h;
    mapWidth = m->getWidth();
    viewWidth = w- mapWidth;
}

void Frame::change(int x, int y, unsigned char c) {
    pixels[y][x] = c;
}

void Frame::drawRect(int x, int h, int angle, int color) {
    int w = (width - mapWidth)/angle;
    x*=w;
    for (int i = 0; i<w && x+i<viewWidth; ++i)
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
        for (int j = 0; j < width- mapWidth; ++j)
            pixels[i][j] = 0;
}

void Frame::drawMap(Map *m) {
    for (int i = 0; i<m->getHeight(); ++i)
        for (int j = 0; j< m->getWidth(); ++j)
            pixels[i][j+viewWidth] = m->get(j, i) ? B_BLUE : B_BLACK;
    pixels[m->getPlayerXY().second][m->getPlayerXY().first + viewWidth] = B_GREEN;
}

int Frame::getWidth() const {
    return viewWidth;
}

int Frame::getHeight() const {
    return height;
}


