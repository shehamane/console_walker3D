#include "Square.hpp"

Square::Square(Screen screen, int size) {
    this->size = size;
    this->screen = screen;
    this->texture = '\u25a0';
    show();
}

void Square::keyHandler() {
    char key = screen.getch();
    switch (key) {
        case 'f':
            changeSize(size + 1);
            show();
            break;
        default:
            screen.printWithDelay("Unknown key\n");
    }
    screen.sleep(20);
}

void Square::show() {
    screen.printWithDelay("");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            std::cout << "\u25a0";
        std::cout << std::endl;
    }
}

void Square::changeSize(int new_size) {
    this->size = new_size;
}