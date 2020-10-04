#ifndef CONSOLEWALKER3D_PLAYER_H
#define CONSOLEWALKER3D_PLAYER_H

#include "Map.h"
#include "Frame.h"

class Player {
private:
    double posX, posY;
    double viewAxis, viewAngle{}, viewRadius{};
    double stepDist{}, turnAngle{};
    Map *map;
    Frame *frame;

    void moveX(float offset);

    void moveY(float offset);

    bool checkX(float offset);

    bool checkY(float offset);

    float changeViewAxis(float newAxis);

    std::pair<int, int> castRay(float angle);

public:

    explicit Player(Map *m, Frame *f);

    Player(Map *m, float x, float y, Frame *f);

    void setSpeed(float speed);

    void setTurnSpeed(float speed);

    void setViewAngle(int angle);

    void setViewRadius(float radius);

    float getX() const;

    float getY() const;

    float getViewAxis() const;

    float getViewAngle() const;

    void turn(bool isPositive);

    void see();

    void handleKey(char key);
};

#endif //CONSOLEWALKER3D_PLAYER_H
