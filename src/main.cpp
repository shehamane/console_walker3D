#include "Screen.hpp"
#include "Screen.cpp"
#include "Map.hpp"
#include "Map.cpp"
#include <unistd.h>
#include <string>

int main(int argc, char **argv) {
    Screen screen(120, 30);
    screen.setFPS(60);
    Map m(5, 5);
    m.build();
    m.changeMap(2, "#.#.#");
    m.print();
    sleep(10);
    return 0;
}