#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <termios.h>
#include "Screen.h"


Screen::Screen(int w, int h) {
    this->width = w;
    this->height = h;
    this->resize();
    Screen::clear();
    initTermios();
}

Screen::Screen() {
    this->width = 120;
    this->height = 30;
    this->resize();
    Screen::clear();
    initTermios();
}

Screen::~Screen() {
    resetTermios();
}

//input

void Screen::initTermios() {
    tcgetattr(0, &oldIO);
    currentIO = oldIO;
    currentIO.c_lflag &= ~ICANON;
    currentIO.c_lflag &= ~ECHO;
    system("xset r rate 1 10");
    tcsetattr(0, TCSANOW, &currentIO);
}

void Screen::resetTermios() {
    tcsetattr(0, TCSANOW, &oldIO);
    system("xset r rate 600 25");
}

char Screen::getch() {
    tcflush(0, TCIOFLUSH);
    char ch;
    ch = getchar();
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
    milliseconds = 1000 / this->fps;
    time_end = clock() + (delay + milliseconds) * CLOCKS_PER_SEC / 1000;
    while (clock() < time_end) {
    }
}

void Screen::printWithDelay(std::string s, unsigned int delay) {
    clear();
    std::cout << s;
    std::cout.flush();
    this->sleep(delay);
}

void Screen::showFrame(std::vector<std::string> *frame, unsigned int delay) {
    clear();
    for (int i = 0; i<(*frame).size(); ++i)
        std::cout << (*frame)[i];
    std::cout.flush();
    delete frame;
    this->sleep(delay);
}

std::string Screen::charToString(char c) {
    std::string s(1, c);
    return s;
}
