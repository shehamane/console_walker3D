#ifndef CONSOLEWALKER3D_SCREEN_H
#define CONSOLEWALKER3D_SCREEN_H

#include <vector>
#include <string>
#include <termios.h>

class Screen {
public:
    int width, height;
    int fps{};
    struct termios oldIO, currentIO;

    //input
    void initTermios();
    void resetTermios(void);
    char getch(void);

    //output
    void resize() const;
    void clear();
    void printWithDelay(std::string s, unsigned int delay = 0);
    void printWithDelay(std::vector<std::string> frame, unsigned int delay = 0);
    void sleep(unsigned int delay) const;

    static std::string charToString(char c);
public:
    Screen(int w, int h);
    Screen();

    void setFPS(int fps);
};

#endif //CONSOLEWALKER3D_SCREEN_H
