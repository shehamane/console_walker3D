#include <string>
#include <exception>
#include <utility>
#include <vector>
#include <iostream>
#include "Map.h"


Map::Map(int w, int h) {
    this->width = w;
    this->height = h;
    this->scheme = new Scheme(w, h);
}

Map::Map() {
    this->width = this->height = 0;
    this->scheme = nullptr;
}

Map::~Map() {
    delete scheme;
}

void Map::build() {
    std::string map_border(width, '#'), map_field(width - 2, ' ');
    map_field = "#" + map_field + "#";

    for (int i = 0; i < height; ++i)
        scheme->changeLine(i, (i == 0 || i == height - 1) ? map_border : map_field);
}

void Map::build(std::vector<std::string> pattern) {
    if (width == 0 && height == 0) {
        this->height = pattern.size();
        this->width = pattern[0].size();
        this->scheme = new Scheme(width, height);
        for (int i = 0; i < height; i++) {
            if (pattern[i].size() != width)
                throw MapException("Карта имеет не прямоугольную форму");
            scheme->changeLine(i, pattern[i]);
        }
    } else {
        if (pattern.size() != height)
            throw MapException("Высота шаблона не соответствует высоте карты");
        for (int i = 0; i < height; ++i) {
            if (pattern[i].size() != width)
                throw MapException("Ширина шаблона не соответствует ширине карты");

            scheme->changeLine(i, pattern[i]);
        }
    }
}

int Map::getWidth() const {
    return width;
}

int Map::getHeight() const {
    return height;
}

void Map::print() {
    for (int i = 0; i < height; ++i) {
        std::cout << scheme->getLine(i);
        std::cout << '\n';
    }
}

void Map::changeLine(int lineIndex, std::string newLine) {
    this->scheme->changeLine(lineIndex, std::move(newLine));
}

bool Map::get(int x, int y) {
    return scheme->get(y, x);
}

void Map::setPlayerXY(int x, int y) {
    playerX = x;
    playerY = y;
}

std::pair<int, int> Map::getPlayerXY() {
    return std::pair<int, int>(playerX, playerY);
}

Map::Scheme::Scheme(int w, int h) {
    width = w;
    height = h;
    this->scheme = new bool *[h];
    for (int i = 0; i < h; ++i)
        this->scheme[i] = new bool[w];
}

Map::Scheme::~Scheme() {
    for (int i = 0; i < height; ++i)
        delete[] scheme[i];
    delete[] scheme;
}

bool Map::Scheme::charToBool(char c) {
    return c != ' ';
}

char Map::Scheme::boolToChar(bool b) {
    if (b)
        return '#';
    return ' ';
}

void Map::Scheme::changeLine(int lineNumber, std::string newLine) {
    for (int i = 0; i < width; ++i) {
        scheme[lineNumber][i] = charToBool(newLine[i]);
    }
}

bool Map::Scheme::get(int x, int y) {
    return this->scheme[x][y];
}

std::string &Map::Scheme::operator[](int lineNumber) {
    std::string s;
    for (int i = 0; i < width; ++i)
        s += boolToChar(scheme[lineNumber][i]);
    return s;
}

std::string Map::Scheme::getLine(int lineNumber) {
    std::string s;
    for (int i = 0; i < width; ++i)
        s += boolToChar(scheme[lineNumber][i]);
    return s;
}

Map::MapException::MapException(const char *error) {
    m_error = error;
}

const char *Map::MapException::what() const noexcept {
    return m_error.c_str();
}


