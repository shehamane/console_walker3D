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

    int getWidth() const;
    int getHeight() const;

    void setFPS(int fps);

    void sleep(unsigned int delay = 0) const;

    char getch(void);

    static void printPixel(char texture, unsigned char color);

    void showFrame(Frame *frame, unsigned int delay = 0) const;
};

#endif //CONSOLEWALKER3D_SCREEN_H
