#include <ncurses.h>

#include "InputBox.h"

void InputBox::render() {
    wmove(window, 1, 1);
    wclrtoeol(window);
    mvwaddstr(window, 1, 1, buffer.c_str());
    box(window, 0, 0);
    wnoutrefresh(window);
}

void InputBox::deleteChar() {
    if (buffer.length()) {
        buffer.pop_back();
    }
}
