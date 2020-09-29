#include "Player.h"
#include <iostream>

Player::Player(Map *m) {
    map = m;
    posX = posY = 0;
}

Player::Player(Map *m, float x, float y) {
    map = m;
    posX = x;
    posY = y;
}

void Player::setSpeed(float speed) {
    stepDist = speed;
}

float Player::getX() { return posX; }

float Player::getY() { return posY; }

void Player::changeX(float offset) { posX += offset; }

void Player::changeY(float offset) { posY += offset; }

bool Player::checkX(float offset) {
    return (posX + offset >= 0) && (posX + offset < map->getWidth()) && !(map->get((int) posY, (int) (posX + offset)));
}

bool Player::checkY(float offset) {
    return (posY + offset >= 0) && (posY + offset < map->getHeight()) &&
           !(map->get((int) (posY + offset), (int) posX));
}


void Player::step(char direciton) {
    switch (direciton) {
        case 'w':
            if (checkY(-stepDist))
                changeY(-stepDist);
            break;
        case 's':
            if (checkY(stepDist))
                changeY(stepDist);
            break;
        case 'd':
            if (checkX(stepDist))
                changeX(stepDist);
            break;
        case 'a':
            if (checkX(-stepDist))
                changeX(-stepDist);
            break;
    }
}