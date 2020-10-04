#include "../lib/Screen.h"
#include "../lib/Square.h"

#include <iostream>

int main(){
    setlocale(LC_ALL, ".866");
    try{
        Screen screen(50, 20);
        screen.setFPS(60);
        Square s(&screen, 5);
        while(true){
            s.keyHandler();
        }
    } catch (Map::MapException e) {
        std::cout << e.what();
    }

    return 0;
}