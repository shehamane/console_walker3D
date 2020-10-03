#include "Player.h"
#include <cmath>

Player::Player(Map *m, Frame *f) {
    map = m;
    posX = posY = 0;
    viewAxis = 0;
    frame = f;
}

Player::Player(Map *m, float x, float y, Frame *f) {
    map = m;
    posX = x;
    posY = y;
    viewAxis = 0;
    frame = f;
}

void Player::setSpeed(float speed) {
    stepDist = speed;
}

float Player::getX() { return posX; }

float Player::getY() { return posY; }

void Player::moveX(float offset) { posX += offset; }

void Player::moveY(float offset) { posY += offset; }

bool Player::checkX(float offset) {
    return (posX + offset >= 0) && (posX + offset < map->getWidth()) && !(map->get((int) (posX + offset), (int) posY));
}

bool Player::checkY(float offset) {
    return (posY + offset >= 0) && (posY + offset < map->getHeight()) &&
           !(map->get((int) posX, (int) (posY + offset)));
}

float Player::getViewAxis() {
    return this->viewAxis;
}

float Player::getViewAngle() {
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
    this->viewAngle = angle * M_PI / 180;
}

void Player::handleKey(char key) {
    switch (key) {
        case 'w':
            if (checkY(-stepDist)) {
                frame->change((int) posX, (int) posY, ' ');
                moveY(-stepDist);
                frame->change((int) posX, (int) posY, 'P');
            }
            break;
        case 's':
            if (checkY(stepDist)) {
                frame->change((int) posX, (int) posY, ' ');
                moveY(stepDist);
                frame->change((int) posX, (int) posY, 'P');
            }
            break;
        case 'd':
            if (checkX(stepDist)) {
                frame->change((int) posX, (int) posY, ' ');
                moveX(stepDist);
                frame->change((int) posX, (int) posY, 'P');
            }
            break;
        case 'a':
            if (checkX(-stepDist)) {
                frame->change((int) posX, (int) posY, ' ');
                moveX(-stepDist);
                frame->change((int) posX, (int) posY, 'P');
            }
            break;
        case 'q':
            turn(false);
            break;
        case 'e':
            turn(true);
            break;
        case '`':
            throw Map::MapException("quit");
    }
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
