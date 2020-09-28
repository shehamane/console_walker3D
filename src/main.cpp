#include "Screen.hpp"
#include "Screen.cpp"
#include "Map.hpp"
#include "Map.cpp"
#include <unistd.h>
#include <string>
#include <vector>

void initMap(Map *m) {
    std::vector<std::string> pattern = {
            "##########",
            "#........#",
            "#........#",
            "#........#",
            "##########",
    };
    (*m).build(pattern);
}

int main(int argc, char **argv) {
    try {
        Screen screen(120, 30);
        screen.setFPS(60);
        Map m(10, 5);
        initMap(&m);
        sleep(10);
    } catch (std::exception e) {
        printf("%s", e.what());
    }
    return 0;
}