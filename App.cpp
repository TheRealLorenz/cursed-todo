#include <ncurses.h>

#include "App.h"

App::App() {
    initscr();
    cbreak();
    noecho();
    nonl();
    intrflush(stdscr, FALSE);
    keypad(stdscr, TRUE);
    curs_set(0);

    todos.push_back(Todo("Fare il bucato"));
    todos.push_back(Todo("Fare la spesa"));
    todos.push_back(Todo("Andare alletto"));
}

App::~App() { endwin(); }

void App::run() {
    box(stdscr, 0, 0);
    this->render();

    while (!should_quit) {
        int ch = getch();
        on_key_event(ch);

        render();
    }
}

void App::on_key_event(int key) {
    switch (key) {
        case 'q': {
            this->should_quit = true;
            break;
        }
        case KEY_UP: {
            if (cursor) {
                cursor--;
            }
            break;
        }
        case KEY_DOWN: {
            if (cursor != todos.size() - 1) {
                cursor++;
            }
            break;
        }
        case '\r': {
            if (!todos.size()) break;

            todos.at(cursor).toggleCompleted();
            break;
        }
    }
}

void App::render() const {
    int line = 1;

    attron(A_BOLD);
    mvaddstr(line, 1, "TODO:");
    attroff(A_BOLD);
    line += 2;

    if (!todos.size()) {
        mvaddstr(line, 1, "> ");
        line++;
    } else {
        for (int i = 0; i < todos.size(); i++) {
            mvaddstr(line, 1, cursor == i ? "> " : "  ");
            addstr(todos[i].isCompleted() ? "[x] " : "[ ] ");
            addstr(todos[i].getValue().c_str());

            line++;
        }
    }

    if (focus == INPUT) {
    }
    wnoutrefresh(stdscr);

    doupdate();
}
