#include "lib/Screen.h"
#include "lib/Map.h"
#include "lib/Player.h"
#include "lib/World.h"
#include "lib/Frame.h"

#include <unistd.h>
#include <string>
#include <vector>
#include <atomic>
#include <csignal>
#include <cstring>

std::atomic<bool> quit(false);

void got_signal(int) {
    quit.store(true);
}

void initMap(Map *m) {
    std::vector<std::string> pattern = {
            "############################################################",
            "#      #                                                   #",
            "#      #############  #                                    #",
            "#      #           #  #                                    #",
            "#      #  ####     #  #                                    #",
            "#      #  ##### ####  #                                    #",
            "#      ####           #                                    #",
            "#         #############                                    #",
            "#                                                          #",
            "############################################################"

    };
    (*m).build(pattern);
}

int main(int argc, char **argv) {
    {
        struct sigaction sa{};
        memset(&sa, 0, sizeof(sa));
        sa.sa_handler = got_signal;
        sigfillset(&sa.sa_mask);
        sigaction(SIGINT, &sa, nullptr);
    }

    try {
        Map m;
        initMap(&m);

        Screen screen(m.getWidth(), m.getHeight() + 1);
        screen.setFPS(60);
        Frame frame(&m);

        Player p(&m, 1.0, 1.0, &frame);
        p.setSpeed(1);
        p.setTurnSpeed(1);
        p.setViewAngle(360);
        p.setViewRadius(10);
        frame.change(p.getX(), p.getY(), 'P');

        World world(&m, &p, &frame);

        m.print();

        std::pair<int, int> looked(-1, -1), last(-1, -1);

        while (true) {
//            screen.printWithDelay(std::to_string(p.getViewAxis()) + " " + std::to_string(p.getX()) + " " + std::to_string(p.getY()));
            screen.showFrame(&frame);
            p.handleKey(screen.getch());
            looked = p.castRay(p.getViewAxis());
            if (last.first != -1)
                frame.change(last.first, last.second, '#');
            if (looked.first != -1)
                frame.change(looked.first, looked.second, 'L');
            last.first = looked.first;
            last.second = looked.second;
            if (quit.load()) break;
        }

        sleep(10);
    } catch (Map::MapException e) {
        printf("%s", e.what());
    }
    return 0;
}