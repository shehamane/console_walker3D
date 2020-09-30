#include "lib/Screen.h"
#include "lib/Map.h"
#include "lib/Player.h"
#include "lib/Minimap.h"

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
            "##############################",
            "#                            #",
            "#      #############  #      #",
            "#      #           #  #      #",
            "#    # #  ####     #  #      #",
            "#         ##### ####  #      #",
            "#    ######           #      #",
            "#         #############      #",
            "#                            #",
            "##############################"

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
        Screen screen(120, 30);
        screen.setFPS(40);

        Map m;
        initMap(&m);

        Player p(&m, 1.0, 1.0);
        p.setSpeed(1);

        Minimap mp(&m, &p);

        m.print();

        while (true) {
            screen.showFrame(mp.toFrame());
            p.step(screen.getch());
            if (quit.load()) break;
        }

        sleep(10);
    } catch (Map::MapException e) {
        printf("%s", e.what());
    }
    return 0;
}