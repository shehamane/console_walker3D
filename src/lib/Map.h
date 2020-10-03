#ifndef CONSOLEWALKER3D_MAP_H
#define CONSOLEWALKER3D_MAP_H

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
        ~Scheme();

        void changeLine(int lineNumber, std::string newLine);

        std::string &operator[](int i);

        std::string getLine(int i);

        bool get(int x, int y);
    };

    class MapException : public std::exception {
    private:
        std::string m_error;

    public:
        explicit MapException(const char* error);

        const char* what() const noexcept override;
    };

private:
    int width, height;
    Scheme *scheme{};
public:
    Map();
    Map(int w, int h);
    ~Map();

    int getWidth() const;
    int getHeight() const;

    void build();
    void build(std::vector<std::string> pattern);
    void print();
    void changeLine(int lineIndex, std::string newLine);
    bool get(int x, int y);
};

#endif //CONSOLEWALKER3D_MAP_H
