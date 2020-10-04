#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <termios.h>
#include "Screen.h"
#include "colors.h"

#define home()            printf(ESC "[H") //Move cursor to the indicated row, column (origin at 1,1)
#define clrscr()        printf(ESC "[2J") //lear the screen, move to (1,1)
#define gotoxy(x, y)        printf(ESC "[%d;%dH", y, x);
#define visible_cursor() printf(ESC "[?251");
//Set Display Attribute Mode	<ESC>[{attr1};...;{attrn}m
#define resetcolor() printf(ESC "[0m")
#define set_display_atrib(color)    printf(ESC "[%dm",color)

Screen::Screen(int w, int h) {
    this->width = w;
    this->height = h;
    this->resize();
    clrscr();
    initTermios();
}

Screen::Screen() {
    this->width = 120;
    this->height = 30;
    this->resize();
    clrscr();
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

void Screen::sleep(unsigned int delay = 0) const {
    double milliseconds;
    clock_t time_end;
    milliseconds = 1000 / this->fps;
    time_end = clock() + (delay + milliseconds) * CLOCKS_PER_SEC / 1000;
    while (clock() < time_end) {
    }
}

void Screen::showFrame(Frame *frame, unsigned int delay) {
    home();
    clrscr();
    for (int i = 0; i < frame->pixels.size(); ++i) {
        for (int j = 0; j < frame->pixels[i].size(); ++j)
            printPixel(frame->pixels[i][j]);
        printf("\n");
    }
    this->sleep(delay);
}

void Screen::showFrame(std::vector<std::string> *frame, unsigned int delay) {
    home();
    clrscr();
    gotoxy(0, (height - frame->size()) / 2);
    for (int i = 0; i < (*frame).size(); ++i) {
        for (int j = 0; j < (*frame)[i].size(); ++j)
            printPixel((*frame)[i][j]);
        printf("\n");
    }
    std::cout.flush();
    delete frame;
    this->sleep(delay);
}

std::string Screen::charToString(char c) {
    std::string s(1, c);
    return s;
}

template<typename T>
void Screen::printWithDelay(T s, unsigned int delay) {
    std::cout << s;
    std::cout.flush();
    this->sleep(delay);
}

void Screen::printPixel(unsigned char color) {
    set_display_atrib(color);
    printf(" ");
    resetcolor();
}

