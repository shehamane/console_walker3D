#ifndef CONSOLEWALKER3D_PLAYER_H
#define CONSOLEWALKER3D_PLAYER_H

#include "Map.h"

class Player{
private:
    float posX, posY;
    float stepDist;
    Map *map;

public:
    explicit Player(Map *m);
    Player(Map *m, float x, float y);
    void setSpeed(float speed);

    float getX();
    float getY();
    void changeX(float offset);
    void changeY(float offset);
    bool checkX(float offset);
    bool checkY(float offset);

    void step(char direciton);
};

#endif //CONSOLEWALKER3D_PLAYER_H
