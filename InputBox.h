#include <ncurses.h>

#include <string>

class InputBox {
private:
    WINDOW *window;
    std::string buffer;

public:
    InputBox(int x, int y, std::string buffer = "");
    ~InputBox();

    const std::string& getValue() const { return buffer; }
    void addChar(char c);
    void deleteChar();
    void render() const;
};
