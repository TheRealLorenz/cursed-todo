#ifndef APP_H_
#define APP_H_

#include <string>
#include <vector>

#include "InputBox.h"
#include "Todo.h"

class App {
private:
    bool should_quit = false;
    std::vector<Todo> todos;
    int cursor = 0;
    std::unique_ptr<InputBox> inputBox = nullptr;

    void on_key_event(int key);
    void render() const;

public:
    App();
    ~App();
    void run();
};

#endif
