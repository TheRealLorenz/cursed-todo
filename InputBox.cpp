#include <ncurses.h>

#include "InputBox.h"

InputBox::InputBox(int x, int y, std::string buffer) : buffer(buffer) {
    window = newwin(3, 20, y, x);
    curs_set(1);
}

InputBox::~InputBox() {
    delwin(window);
    curs_set(0);
}

void InputBox::render() const {
    wmove(window, 1, 1);
    wclrtoeol(window);
    mvwaddstr(window, 1, 1, buffer.c_str());
    box(window, 0, 0);
    wnoutrefresh(window);
}

void InputBox::addChar(char c) {
    buffer += c;

    int width, height;
    getmaxyx(window, height, width);

    // I need to subtract the border (2) and
    // the cursor (1)
    if (buffer.length() > width - 3) {
        wresize(window, height, width + 10);
    }
}

void InputBox::deleteChar() {
    if (buffer.length()) {
        buffer.pop_back();
    }
}
