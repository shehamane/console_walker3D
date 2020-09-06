#include "Screen.hpp"
#include "Screen.cpp"
#include <unistd.h>

int main(int argc, char **argv) {
    Screen screen(120, 30);
    screen.setFPS(20);
    sleep(10);
    return 0;
}