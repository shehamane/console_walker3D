#include "Screen.hpp"
#include "Screen.cpp"
#include "Square.hpp"
#include "Square.cpp"
#include <unistd.h>
#include <string>

int main(int argc, char **argv) {
    Screen screen(120, 30);
    screen.setFPS(60);
    Square square(screen, 10);
    while (1) {
        square.keyHandler();
    }
    sleep(10);
    return 0;
}