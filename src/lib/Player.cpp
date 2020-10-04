#include "Player.h"
#include <cmath>
#include <iostream>

Player::Player(Map *m, Frame *f) {
    map = m;
    posX = posY = 0;
    viewAxis = 0;
    frame = f;
    frame->change(this->getX(), this->getY(), 'P');
}

Player::Player(Map *m, float x, float y, Frame *f) {
    map = m;
    posX = x;
    posY = y;
    viewAxis = 0;
    frame = f;
    frame->change(this->getX(), this->getY(), 'P');
}

void Player::setSpeed(float speed) {
    stepDist = speed;
}

float Player::getX() const { return posX; }

float Player::getY() const { return posY; }

void Player::moveX(float offset) { posX += offset; }

void Player::moveY(float offset) { posY += offset; }

bool Player::checkX(float offset) {
    return (posX + offset >= 0) && (posX + offset < map->getWidth()) && !(map->get((int) (posX + offset), (int) posY));
}

bool Player::checkY(float offset) {
    return (posY + offset >= 0) && (posY + offset < map->getHeight()) &&
           !(map->get((int) posX, (int) (posY + offset)));
}

float Player::getViewAxis() const {
    return this->viewAxis;
}

float Player::getViewAngle() const {
    return this->viewAngle;
}

float Player::changeViewAxis(float newAxis) {
    this->viewAxis = newAxis;
}

void Player::setTurnSpeed(float speed) {
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
    frame->change((int) posX, (int) posY, ' ');
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
    }
    frame->change((int) posX, (int) posY, 'P');

}

void Player::setViewRadius(float radius) {
    viewRadius = radius;
}

std::pair<int, int> Player::castRay(float angle) {
    for (float c = 0; c < viewRadius; c += 0.01)
        if (map->get((floor)(posX + c * cos(angle)), (floor)(posY + c * sin(angle))))
            return std::make_pair((floor)(posX + c * cos(angle)), (floor)(posY + c * sin(angle)));
    return std::make_pair(-1, -1);
}

void Player::see() {
    float angle;
    std::pair<int, int> lookedXY = castRay(viewAxis);
    frame->change(lookedXY.first, lookedXY.second, '|');

    for (float alpha = 0; alpha < this->viewAngle / 2; alpha +=0.1) {
        angle = viewAxis*180/M_PI + alpha;
        if (angle > 360)
            angle = angle - 360;
        else if (angle<0)
            angle = 360+angle;
        angle *= M_PI / 180;
        lookedXY = castRay(angle);
        frame->change(lookedXY.first, lookedXY.second, '|');

        angle = viewAxis*180/M_PI - alpha;
        if (angle > 360)
            angle = angle - 360;
        else if (angle<0)
            angle = 360+angle;
        angle *= M_PI / 180;
        lookedXY = castRay(angle);
        frame->change(lookedXY.first, lookedXY.second, '|');
    }
}
