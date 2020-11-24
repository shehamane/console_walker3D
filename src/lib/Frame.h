#ifndef CONSOLEWALKER3D_FRAME_H
#define CONSOLEWALKER3D_FRAME_H

#include <vector>
#include "Map.h"

class Frame{
private:
    int width, height, mapWidth, viewWidth;
public:
    std::vector<std::vector<unsigned char>> pixels;
    Frame(int w, int h, Map* m);

    void drawColumn(int x, int h, int color);
    void drawRect(int x, int h, int angle, int color);
    void drawMap(Map* m);
    int getWidth() const;
    int getHeight() const;
    void change(int x, int y, unsigned char c);
    void erase();
};

#endif //CONSOLEWALKER3D_FRAME_H
