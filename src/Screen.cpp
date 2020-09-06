#include "Screen.hpp"
#include <iostream>
#include <string>
#include <ctime>
#include <termios.h>

Screen::Screen(int w, int h) {
    Screen::oldIO = {0};
    this->width = w;
    this->height = h;
    this->resize();
    Screen::clear();
}

//input

void Screen::initTermios() {
    tcgetattr(0, &Screen::oldIO);
    Screen::currentIO = Screen::oldIO;
    Screen::currentIO.c_lflag &= ~ICANON;
    Screen::currentIO.c_lflag &= ~ECHO;
    tcsetattr(0, TCSANOW, &Screen::currentIO);
}

void Screen::resetTermios(void) {
    tcsetattr(0, TCSANOW, &Screen::oldIO);
}

char Screen::getch() {
    char ch;
    initTermios();
    ch = getchar();
    resetTermios();
    return ch;
}

//output

void Screen::setFPS(int fps) {
    this->fps = fps;
}

void Screen::resize() const {
    printf("\e[8;%d;%d;t", this->height, this->width);
}

void Screen::clear() {
    system("clear");
}

void Screen::sleep(unsigned int delay = 0) const {
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
