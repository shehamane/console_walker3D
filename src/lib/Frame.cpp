#include "Frame.h"
#include "colors.h"

Frame::Frame(int w, int h, Map *m) : pixels(h, std::vector<std::pair<char, unsigned char>>(w,
                                                                                           std::pair<char, unsigned char>())) {
    width = w;
    height = h;
    mapWidth = m->getWidth();
    viewWidth = w - mapWidth;
}

void Frame::change(int x, int y, char texture, unsigned char color) {
    pixels[y][x].first = texture;
    pixels[y][x].second = color;
}


void Frame::drawBackground(int x, int angle) {
    int w = (width - mapWidth) / angle;
    x *= w;

    for (int j = 0; j < w && x + j < viewWidth; ++j) {
        for (int i = 0; i < height / 2; ++i)
            change(x + j, i, pixels[i][x + j].first, B_CYAN);
        for (int i = height / 2; i < height; ++i)
            change(x + j, i, pixels[i][x + j].first, B_GREEN);
    }
}

void Frame::drawRect(int x, int h, int angle, char texture, unsigned char color) {
    int w = (width - mapWidth) / angle;
    x *= w;
    for (int i = 0; i < w && x + i < viewWidth; ++i)
        drawColumn(x + i, h, texture, color);
}

void Frame::drawColumn(int x, int h, char texture, unsigned char color) {
    if (h > height)
        h = height;
    int start = (height - h) / 2;
    int end = height - 1 - (height - h) / 2;
    for (int i = 0; i < start; ++i)
        change(x, i, ' ', B_CYAN);
    for (int i = start; i <= end; ++i)
        change(x, i, texture, color);
    for (int i = end + 1; i < height; ++i)
        change(x, i, ' ', B_GREEN);
}

void Frame::erase() {
    for (int i = 0; i < height; ++i)
        for (int j = 0; j < width - mapWidth; ++j)
            change(j, i, ' ', 0);
}

void Frame::drawMap(Map *m) {
    for (int i = 0; i < m->getHeight(); ++i)
        for (int j = 0; j < m->getWidth(); ++j) {
            pixels[i][j + viewWidth].first = ' ';
            pixels[i][j + viewWidth].second = m->get(j, i) ? B_BLUE : B_BLACK;
        }
    change(m->getPlayerXY().first + viewWidth, m->getPlayerXY().second, ' ', B_GREEN);
}

int Frame::getWidth() const {
    return viewWidth;
}

int Frame::getHeight() const {
    return height;
}

void Frame::drawByDist(double dist, int x, int viewAngle, double viewRadius) {
    if (dist != -1) {
        if (dist < viewRadius * ((double)1 / 3))
            this->drawRect((int) x, (int) (this->getHeight() / dist), (int) viewAngle, ' ',
                            B_WHITE);
        else {
            if (dist < viewRadius * ((double)2 / 3))
                this->drawRect((int) x, (int) (this->getHeight() / dist), (int) viewAngle, '#',
                                F_RED);
            else if (dist < viewRadius * 3 / 4)
                this->drawRect((int) x, (int) (this->getHeight() / dist), (int) viewAngle, '#',
                                F_WHITE);
            else
                this->drawRect((int) x, (int) (this->getHeight() / dist), (int) viewAngle, ':',
                                F_WHITE);
            this->drawBackground((int) x, (int) viewAngle);
        }
    } else
        this->drawBackground((int) x, (int) viewAngle);
}


