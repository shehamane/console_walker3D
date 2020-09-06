#ifndef CONSOLEWALKER3D_SCREEN_HPP
#define CONSOLEWALKER3D_SCREEN_HPP

#include <string>

class Screen {
private:
    int width, height;
    int fps;

    void resize();
    void clear();
    void sleep(unsigned int delay);
    void printWithDelay(std::string s, unsigned int delay);
public:
    Screen(int w, int h);
    void setFPS(int fps);
};


#endif //CONSOLEWALKER3D_SCREEN_HPP
