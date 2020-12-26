#ifndef CONSOLEWALKER3D_FRAME_H
#define CONSOLEWALKER3D_FRAME_H

#include <vector>
#include "Map.h"

class Frame{
private:
    int width, height, mapWidth, viewWidth;
public:
    std::vector<std::vector<std::pair<char, unsigned char>>> pixels;
    Frame(int w, int h, Map* m);

    void drawColumn(int x, int h, char texture, unsigned char color);
    void drawRect(int x, int h, int angle, char texture, unsigned char color);
    void drawByDist(double dist, int x, int viewAngle, double viewRadius);
    void drawBackground(int x, int angle);
    void drawMap(Map* m);
    int getWidth() const;
    int getHeight() const;
    void change(int x, int y, char texture, unsigned char color);
    void erase();
};

#endif //CONSOLEWALKER3D_FRAME_H
