#include "Player.h"
#include <cmath>
#include "colors.h"

Player::Player(Map *m, Frame *f) {
    map = m;
    posX = posY = 0;
    viewAxis = 0;
    frame = f;
}

Player::Player(Map *m, double x, double y, Frame *f) {
    map = m;
    m->setPlayerXY((int)x, (int)y);
    posX = x;
    posY = y;
    viewAxis = 0;
    frame = f;
}

void Player::setSpeed(double speed) {
    stepDist = speed;
}

double Player::getX() const { return posX; }

double Player::getY() const { return posY; }

void Player::moveX(double offset) { posX += offset; }

void Player::moveY(double offset) { posY += offset; }

bool Player::checkX(double offset) {
    return (posX + offset >= 0) && (posX + offset < map->getWidth()) && !(map->get((int) (posX + offset), (int) posY));
}

bool Player::checkY(double offset) {
    return (posY + offset >= 0) && (posY + offset < map->getHeight()) &&
           !(map->get((int) posX, (int) (posY + offset)));
}

double Player::getViewAxis() const {
    return this->viewAxis;
}

double Player::getViewAngle() const {
    return this->viewAngle;
}

double Player::changeViewAxis(double newAxis) {
    this->viewAxis = newAxis;
}

void Player::setTurnSpeed(double speed) {
    this->turnAngle = speed;
}

void Player::turn(bool isPositive) {
    int dirMultiplier = isPositive ? 1 : -1;
    viewAxis *= 180 / M_PI;
    viewAxis += dirMultiplier * turnAngle;
    viewAxis -= 360 * floor(viewAxis / 360);
    viewAxis *= M_PI / 180;
}

void Player::setViewAngle(int angle) {
    this->viewAngle = angle;
}

void Player::handleKey(char key) {
    switch (key) {
        case 'w':
            if (checkY(-stepDist))
                moveY(-stepDist);
            break;
        case 's':
            if (checkY(stepDist))
                moveY(stepDist);
            break;
        case 'd':
            if (checkX(stepDist))
                moveX(stepDist);
            break;
        case 'a':
            if (checkX(-stepDist))
                moveX(-stepDist);
            break;
        case 'q':
            turn(false);
            break;
        case 'e':
            turn(true);
            break;
        case '`':
            throw Map::MapException("quit");
            break;
        default:
            break;
    }
    map->setPlayerXY((int) posX, (int) posY);
}

void Player::setViewRadius(double radius) {
    viewRadius = radius;
}

double Player::castRay(double angle) {
    for (double c = 0; c < viewRadius; c += 0.01)
        if (map->get((floor)(posX + c * cos(angle)), (floor)(posY + c * sin(angle))))
            return c;
    return -1;
}

void Player::see() {
    double angle, dist;

    for (double alpha = 0, i = 0; alpha < this->viewAngle / 2; alpha += viewAngle / frame->getWidth(), ++i) {
        angle = viewAxis * 180 / M_PI + alpha;
        if (angle > 360)
            angle = angle - 360;
        else if (angle < 0)
            angle = 360 + angle;
        angle *= M_PI / 180;
        dist = castRay((double) angle);

        frame->drawByDist(dist, (int)i, (int)viewAngle, viewRadius);



        angle = viewAxis * 180 / M_PI - alpha;
        if (angle > 360)
            angle = angle - 360;
        else if (angle < 0)
            angle = 360 + angle;
        angle *= M_PI / 180;
        dist = castRay((double) angle);

        frame->drawByDist(dist, (int)(frame->getWidth() - i), (int)viewAngle, viewRadius);
    }
}
