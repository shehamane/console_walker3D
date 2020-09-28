#ifndef CONSOLEWALKER3D_SCREEN_HPP
#define CONSOLEWALKER3D_SCREEN_HPP

#include <string>
#include <termios.h>

class Screen {
private:
    int width, height;
    int fps;
    struct termios oldIO, currentIO;

    //input
    void initTermios();
    void resetTermios(void);
    char getch(void);

    //output
    void resize() const;
    void clear();
    void printWithDelay(std::string s, unsigned int delay);
    void sleep(unsigned int delay) const;
public:
    Screen(int w, int h);
    Screen();
    ~Screen();

    void setFPS(int fps);



};

#endif //CONSOLEWALKER3D_SCREEN_HPP
