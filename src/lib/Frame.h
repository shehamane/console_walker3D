#ifndef CONSOLEWALKER3D_FRAME_H
#define CONSOLEWALKER3D_FRAME_H

#include <vector>
#include <string>
#include "Map.h"

class Frame{
private:
    int width, height;
    Map *map;
public:
    std::vector<std::string> chars;
    Frame(int w, int h);
    Frame(Map *map);

    void update();
    void change(int x, int y, char c);
};

#endif //CONSOLEWALKER3D_FRAME_H
