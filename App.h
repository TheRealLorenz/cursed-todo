#ifndef APP_H_
#define APP_H_

#include <string>
#include <vector>

#include "InputBox.h"
#include "Todo.h"

enum Focus { TODO, INPUT };

class App {
private:
    bool should_quit = false;
    std::vector<Todo> todos;
    int cursor = 0;
    enum Focus focus = TODO;

    void on_key_event(int key);
    void render() const;

public:
    App();
    ~App();
    void run();
};

#endif
