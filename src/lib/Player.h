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

    void moveX(double offset);

    void moveY(double offset);

    bool checkX(double offset);

    bool checkY(double offset);

    double changeViewAxis(double newAxis);

    double castRay(double angle);

public:

    explicit Player(Map *m, Frame *f);

    Player(Map *m, double x, double y, Frame *f);

    void setSpeed(double speed);

    void setTurnSpeed(double speed);

    void setViewAngle(int angle);

    void setViewRadius(double radius);

    double getX() const;

    double getY() const;

    double getViewAxis() const;

    double getViewAngle() const;

    void turn(bool isPositive);

    void see();

    void handleKey(char key);
};

#endif //CONSOLEWALKER3D_PLAYER_H
