#ifndef CONSOLEWALKER3D_PLAYER_H
#define CONSOLEWALKER3D_PLAYER_H

#include "Map.h"
#include "Frame.h"

class Player {
private:
    float posX, posY;
    float viewAxis, viewAngle, viewRadius;
    float stepDist, turnAngle;
    Map *map;
    Frame *frame;

    void moveX(float offset);

    void moveY(float offset);

    bool checkX(float offset);

    bool checkY(float offset);

    float changeViewAxis(float newAxis);

public:

    std::pair<int, int> castRay(float angle);

    explicit Player(Map *m, Frame *f);

    Player(Map *m, float x, float y, Frame *f);

    void setSpeed(float speed);

    void setTurnSpeed(float speed);

    void setViewAngle(int angle);

    void setViewRadius(float radius);

    float getX();

    float getY();

    float getViewAxis();

    float getViewAngle();

    void turn(bool isPositive);

    void handleKey(char key);
};

#endif //CONSOLEWALKER3D_PLAYER_H
