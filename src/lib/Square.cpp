#include "iostream"
#include "Screen.h"
#include "Square.h"
#include "colors.h"


Square::Square(Screen *screen, int size) {
    this->size = size;
    this->screen = screen;
    this->texture = B_RED;
    this->show();
}

void Square::keyHandler() {
    char key = screen->getch();
    switch (key) {
        case 'f':
            changeSize(size + 1);
            show();
            break;
        case 'g':
            changeSize(size - 1);
            show();
            break;
        case '`':
            throw Map::MapException("quit");
            break;
//        default:
//            screen->printWithDelay("Unknown key\n");
    }
    screen->sleep(20);
}

void Square::show() {
    auto *frame = new std::vector<std::string>(size);
    std::string row(size, (char) texture);
    for (int i = 0; i < size; i++) {
        (*frame)[i] = row+"\n";
    }
}

void Square::changeSize(int new_size) {
    this->size = new_size;
}
