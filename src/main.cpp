#include "lib/Screen.h"
#include "lib/Map.h"
#include "lib/Player.h"
#include "lib/Minimap.h"

#include <unistd.h>
#include <string>
#include <vector>

void initMap(Map *m) {
    std::vector<std::string> pattern = {
            "###########################",
            "#                         #",
            "#                         #",
            "#                         #",
            "#                         #",
            "#                         #",
            "#                         #",
            "#                         #",
            "#                         #",
            "###########################"
    };
    (*m).build(pattern);
}

int main(int argc, char **argv) {
    try {
        Screen screen(120, 30);
        screen.setFPS(20);

        Map m(27, 10);
        initMap(&m);

        Player p(&m, 1.0, 1.0);
        p.setSpeed(1);

        Minimap mp(&m, &p);

        m.print();

        while(true){
            screen.showFrame(mp.toFrame());
            p.step(screen.getch());
        }

        sleep(10);
    } catch (std::exception e) {
        printf("%s", e.what());
    }
    return 0;
}