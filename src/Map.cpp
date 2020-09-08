#include "Map.hpp"
#include <string>


Map::Map(int w, int h) {
    this->width = w;
    this->height = h;
    this->scheme = new Scheme(w, h);
}

void Map::build() {
    std::string map_border = "", map_field = "";
    for (int i = 0; i < width; ++i) {
        map_border += '#';
        map_field += (i == 0 || i == width - 1) ? '#' : '.';
    }
    for (int i = 0; i < height; ++i)
        scheme->changeLine(i, (i == 0 || i == height - 1) ? map_border : map_field);
}

void Map::print() {
    for (int i = 0; i < height; ++i) {
        std::cout << scheme->getLine(i);
        std::cout << '\n';
    }
}

void Map::changeMap(int lineIndex, std::string newLine) {
    this->scheme->changeLine(lineIndex, newLine);
}

Map::Scheme::Scheme(int w, int h) {
    this->scheme = new std::string[h];
}

void Map::Scheme::changeLine(int i, std::string newLine) {
    this->scheme[i] = newLine;
}

std::string &Map::Scheme::operator[](int i) {
    return this->scheme[i];
}

std::string Map::Scheme::getLine(int i) {
    return this->scheme[i];
}
