#ifndef CONSOLEWALKER3D_SCREEN_HPP
#define CONSOLEWALKER3D_SCREEN_HPP

#include <string>
#include <termios.h>

class Screen {
private:
    int width, height;
    int fps{};
    struct termios oldIO, currentIO;

    //input
    void initTermios();
    void resetTermios(void);

    //output
    void resize() const;
    static void clear();
public:
    Screen(int w, int h);
    Screen();

    void setFPS(int fps);
    char getch(void);
    void printWithDelay(std::string s, unsigned int delay);
    void sleep(unsigned int delay) const;


};

#endif //CONSOLEWALKER3D_SCREEN_HPP
