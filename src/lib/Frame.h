#ifndef CONSOLEWALKER3D_FRAME_H
#define CONSOLEWALKER3D_FRAME_H

#include <vector>
#include <string>
#include "Map.h"

class Frame{
private:
    int width, height;
public:
    std::vector<std::string> chars;
    Frame(int w, int h);
    Frame(Map *map);

    void change(int x, int y, char c);
};

#endif //CONSOLEWALKER3D_FRAME_H
