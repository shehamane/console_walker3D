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

    try {
        Map m;
        initMap(&m);

        Screen screen(m.getWidth(), m.getHeight() + 1);
        screen.setFPS(60);
        Frame frame(&m);

        Player p(&m, 1.0, 1.0, &frame);
        p.setSpeed(0.3);
        p.setTurnSpeed(10);
        p.setViewAngle(60);
        p.setViewRadius(1000);

        World world(&m, &p, &frame);

        m.print();

        while (true) {
//            screen.printWithDelay(std::to_string(p.getViewAxis()) + " " + std::to_string(p.getX()) + " " + std::to_string(p.getY()));
            screen.showFrame(&frame);
            frame.update();
            p.handleKey(screen.getch());
            p.see();
        }

    } catch (Map::MapException e) {
        printf("%s", e.what());
    }
    return 0;
}