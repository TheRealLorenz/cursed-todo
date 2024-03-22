#include <ncurses.h>

#include <string>

class InputBox {
private:
    WINDOW *window;
    std::string buffer;

public:
    InputBox(int x, int y, std::string buffer = "");
    ~InputBox();

    void addChar(char c) { buffer += c; }
    const std::string& getValue() const { return buffer; }
    void deleteChar();
    void render() const;
};
