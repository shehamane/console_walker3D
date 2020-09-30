#include "../lib/Screen.h"
#include "../lib/Square.h"

#include <iostream>
#include <atomic>
#include <csignal>
#include <cstring>

std::atomic<bool> quit(false);

void got_signal(int) {
    quit.store(true);
}

int main(){
    {
        struct sigaction sa{};
        memset(&sa, 0, sizeof(sa));
        sa.sa_handler = got_signal;
        sigfillset(&sa.sa_mask);
        sigaction(SIGINT, &sa, nullptr);
    }

    try{
        Screen screen(200, 200);
        screen.setFPS(60);
        Square s(&screen, 5);
        while(true){
            s.keyHandler();
            if (quit.load()) break;
        }
    } catch (std::exception e) {
        std::cout << e.what();
    }

    return 0;
}