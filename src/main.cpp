#include "lib/Screen.h"
#include "lib/Map.h"
#include "lib/Player.h"
#include "lib/World.h"
#include "lib/Frame.h"

#include <string>
#include <vector>

void initMap(Map *m) {
    std::vector<std::string> pattern = {
            "############################################################",
            "#      #                       #           #               #",
            "#      #############  #        #           #               #",
            "#      #           #  #        #           #               #",
            "#      #  ####     #  #        #           #               #",
            "#      #  ##### ####  #        #           #               #",
            "#      ####           #        #####   #####               #",
            "#         #############                                    #",
            "#                                                          #",
            "############################################################"

    };
    (*m).build(pattern);
}

int main(int argc, char **argv) {

    try {
        Map m;
        initMap(&m);

        Screen screen(120+m.getWidth(), 41);
        screen.setFPS(120);
        Frame frame(screen.getWidth(), screen.getHeight()-1, &m);

        Player p(&m, 1.0, 1.0, &frame);
        p.setSpeed(0.3);
        p.setTurnSpeed(10);
        p.setViewAngle(60);
        p.setViewRadius(5);

        World world(&m, &p, &frame);

        screen.showFrame(&frame);
        while (true) {
//            screen.printWithDelay(std::to_string(p.getViewAxis()) + " " + std::to_string(p.getX()) + " " + std::to_string(p.getY()));
            p.handleKey(screen.getch());
            frame.erase();
            p.see();
            screen.showFrame(&frame);
        }

    } catch (Map::MapException e) {
        printf("%s", e.what());
    }
    return 0;
}