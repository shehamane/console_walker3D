#ifndef CONSOLEWALKER3D_MAP_HPP
#define CONSOLEWALKER3D_MAP_HPP

#include <string>

class Map {
public:
    class Scheme {
    private:
        std::string *scheme;
    public:
        Scheme(int w, int h);
        void changeLine(int i, std::string newLine);
        std::string &operator[](int i);
        std::string getLine(int i);
    };
private:
    int width, height;
    Scheme *scheme;
public:
    Map(int w, int h);
    void build();
    void print();
    void changeMap(int lineIndex, std::string newLine);
};


#endif //CONSOLEWALKER3D_MAP_HPP
