#include "../lib/Screen.h"
#include "../lib/Square.h"

#include <iostream>


int main(){
    std::setlocale(LC_ALL, "en_US.UTF-8");    try{
        Screen screen(200, 200);
        screen.setFPS(60);
        Square s(screen, 5);
        while(true){
            s.keyHandler();
        }
    } catch (std::exception e) {
        std::cout << e.what();
    }

    return 0;
}