#ifndef CONSOLEWALKER3D_SQUARE_H
#define CONSOLEWALKER3D_SQUARE_H

#include "Screen.h"

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


#endif //CONSOLEWALKER3D_SQUARE_H
