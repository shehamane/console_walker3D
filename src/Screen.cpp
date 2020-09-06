#include "Screen.hpp"
#include <iostream>
#include <string>
#include <ctime>

Screen::Screen(int w, int h) {
    this->width = w;
    this->height = h;
    this->resize();
    this->clear();
}

void Screen::setFPS(int fps) {
    this->fps = fps;
}

void Screen::resize() {
    printf("\e[8;%d;%d;t", this->height, this->width);
}

void Screen::clear() {
    system("clear");
}

void Screen::sleep(unsigned int delay = 0) {
    double milliseconds;
    clock_t time_end;
    milliseconds = 1000/this->fps;
    time_end = clock() + (delay + milliseconds) * CLOCKS_PER_SEC / 1000;
    while (clock() < time_end) {
    }
}

void Screen::printWithDelay(std::string s, unsigned int delay) {
    std::cout << s;
    std::cout.flush();
    this->sleep(delay);
}
