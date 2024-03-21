#include <ncurses.h>

#include <string>

class InputBox {
private:
    WINDOW *window;
    std::string buffer;

public:
    InputBox(int x, int y, std::string buffer = "");
    ~InputBox();

    std::string getValue() { return buffer; }
    void addChar(char c) { buffer += c; }
    void deleteChar();
    void render();
};
