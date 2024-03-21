#include <ncurses.h>

#include <string>

class InputBox {
private:
    WINDOW *window;
    std::string buffer;

public:
    InputBox(int x, int y, std::string buffer = "") : buffer(buffer) {
        window = newwin(3, 20, y, x);
    }
    ~InputBox() { delwin(window); }

    std::string getValue() { return buffer; }
    void addChar(char c) { buffer += c; }
    void deleteChar();
    void render();
};
