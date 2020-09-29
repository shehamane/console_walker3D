#ifndef CONSOLEWALKER3D_SQUARE_HPP
#define CONSOLEWALKER3D_SQUARE_HPP

#include "Screen.hpp"
#include "iostream"

class Square {
private:
    int size;
    char texture;
    Screen screen;
    void show();

public:
    Square(Screen screen, int size);
    void keyHandler();
    void changeSize(int new_size);
};


#endif //CONSOLEWALKER3D_SQUARE_HPP
