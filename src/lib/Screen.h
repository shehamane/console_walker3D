#ifndef CONSOLEWALKER3D_SCREEN_H
#define CONSOLEWALKER3D_SCREEN_H

#include <vector>
#include <string>
#include <termios.h>
#include <iostream>
#include "Frame.h"

class Screen {
private:
    int width, height;
    int fps;
    struct termios oldIO, currentIO;

    //input
    void initTermios();

    void resetTermios(void);

    //output
    void resize() const;

    template<typename T>
    void printWithDelay(T s, unsigned int delay = 0);

    static std::string charToString(char c);

public:
    Screen(int w, int h);

    Screen();

    ~Screen();

    void setFPS(int fps);

    void sleep(unsigned int delay) const;

    char getch(void);

    void printPixel(unsigned char color);

    void showFrame(Frame *frame, unsigned int delay = 0);
    void showFrame(std::vector<std::string> *frame, unsigned int delay = 0);
};

#endif //CONSOLEWALKER3D_SCREEN_H
