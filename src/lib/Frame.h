#ifndef CONSOLEWALKER3D_FRAME_H
#define CONSOLEWALKER3D_FRAME_H

#include <vector>
#include "Map.h"

class Frame{
private:
    int width, height;
    Map *map;
public:
    std::vector<std::vector<unsigned char>> pixels;
    Frame(int w, int h);
    explicit Frame(Map *map);

    void update();
    void change(int x, int y, unsigned char c);
};

#endif //CONSOLEWALKER3D_FRAME_H
