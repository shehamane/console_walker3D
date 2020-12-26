#include "lib/Screen.h"
#include "lib/Map.h"
#include "lib/Player.h"
#include "lib/Frame.h"

#include <string>
#include <vector>

void initMap(Map *m) {
    std::vector<std::string> pattern = {
            "############################################################",
            "#                              #                           #",
            "#                     #        #           #               #",
            "#                              #           #               #",
            "#          ###                 #                   ###     #",
            "#          # #   ####                      #         #     #",
            "#          ###                 #####   #####               #",
            "#                                                          #",
            "#                                                          #",
            "############################################################"

    };
    (*m).build(pattern);
}

int main(int argc, char **argv) {

    try {
        Map m;
        initMap(&m);

        Screen screen(400+m.getWidth(), 81);
        screen.setFPS(120);
        Frame frame(screen.getWidth(), screen.getHeight()-1, &m);

        Player p(&m, 5.0, 7.0, &frame);
        p.setSpeed(0.1);
        p.setTurnSpeed(3);
        p.setViewAngle(90);
        p.setViewRadius(20);

        while (true) {
//            screen.printWithDelay(std::to_string(p.getViewAxis()) + " " + std::to_string(p.getX()) + " " + std::to_string(p.getY()));
            frame.erase();
            p.see();
            frame.drawMap(&m);
            screen.showFrame(&frame);
            p.handleKey(screen.getch());
        }

    } catch (Map::MapException& e) {
        printf("%s", e.what());
    }
    return 0;
}