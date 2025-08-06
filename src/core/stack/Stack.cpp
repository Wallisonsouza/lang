#include "Stack.h"

Stack::Stack() : current(0) {}

void Stack::save() {
    stack.push_back(current);
}

void Stack::restore() {
    if (stack.empty())
        throw std::runtime_error("No saved positions to restore");
    current = stack.back();
    stack.pop_back();
}

void Stack::reset() {
    current = 0;
    stack.clear();
}

size_t Stack::getPosition() const {
    return current;
}

void Stack::advance() {
    current++;
}

void Stack::retreat() {
    if (current == 0)
        throw std::runtime_error("Already at beginning");
    current--;
}
