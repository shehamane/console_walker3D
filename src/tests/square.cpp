#include "../lib/Screen.h"
#include "../lib/Square.h"

#include <iostream>

int main(){
    try{
        Screen screen(200, 200);
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