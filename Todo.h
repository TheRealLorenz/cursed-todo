#ifndef TODO_H_
#define TODO_H_

#include <string>

using std::string;

class Todo {
private:
    string value;
    bool completed = false;

public:
    Todo(string value) : value(value) {}

    const string &getValue() const { return value; }
    void setValue(string value) { this->value = value; }

    const bool isCompleted() const { return completed; }
    void setCompleted(bool completed) { this->completed = completed; }

    void toggleCompleted() { this->completed = !this->completed; }
};

#endif
