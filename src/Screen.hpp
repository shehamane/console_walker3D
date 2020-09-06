#ifndef CONSOLEWALKER3D_SCREEN_HPP
#define CONSOLEWALKER3D_SCREEN_HPP

#include <string>

class Screen {
private:
    int width, height;
    int fps{};
    static struct termios oldIO, currentIO;

    //input
    void initTermios();
    void resetTermios(void);

    //output
    void resize() const;
    static void clear();
    void sleep(unsigned int delay) const;
    void printWithDelay(std::string s, unsigned int delay);
public:
    char getch(void);
    Screen(int w, int h);
    void setFPS(int fps);
};


#endif //CONSOLEWALKER3D_SCREEN_HPP
