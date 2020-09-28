#ifndef CONSOLEWALKER3D_MAP_HPP
#define CONSOLEWALKER3D_MAP_HPP

#include <string>
#include <exception>
#include <vector>

class Map {
public:
    class Scheme {
    private:
        int width, height;
        bool **scheme;

        static bool charToBool(char c);
        static char boolToChar(bool b);
    public:
        Scheme(int w, int h);

        void changeLine(int lineNumber, std::string newLine);

        std::string &operator[](int i);

        std::string getLine(int i);
    };

    class MapException : public std::exception {
    private:
        std::string m_error;

    public:
        explicit MapException(std::string error);

        const char* what() const noexcept override;
    };

private:
    int width, height;
    Scheme *scheme;
public:
    Map(int w, int h);

    void build();

    void build(std::vector<std::string> pattern);

    void print();

    void changeMap(int lineIndex, std::string newLine);
};


#endif //CONSOLEWALKER3D_MAP_HPP
