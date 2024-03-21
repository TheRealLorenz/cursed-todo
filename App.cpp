#include <ncurses.h>

#include <memory>

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
    render();

    while (!should_quit) {
        int ch = getch();
        on_key_event(ch);

        render();
    }
}

void App::on_key_event(int key) {
    if (inputBox) {
        switch (key) {
            case 27: {
                inputBox = nullptr;
                break;
            }
            case KEY_BACKSPACE: {
                inputBox->deleteChar();
                break;
            }
            case '\r': {
                todos.push_back(Todo(inputBox->getValue()));
                inputBox = nullptr;
                break;
            }
            default:
                inputBox->addChar(key);
                break;
        }
        return;
    }

    switch (key) {
        case 'q': {
            this->should_quit = true;
            break;
        }
        case 'k':
        case KEY_UP: {
            if (cursor) {
                cursor--;
            }
            break;
        }
        case 'j':
        case KEY_DOWN: {
            if (cursor != todos.size() - 1) {
                cursor++;
            }
            break;
        }
        case 'a': {
            inputBox = std::unique_ptr<InputBox>(new InputBox(3, 10, ""));
            break;
        }
        case ' ': {
            if (!todos.size()) break;

            todos.at(cursor).toggleCompleted();
            break;
        }
    }
}

void App::render() const {
    wclear(stdscr);
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
    wnoutrefresh(stdscr);

    if (inputBox) {
        inputBox->render();
    }

    doupdate();
}
