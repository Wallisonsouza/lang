#ifndef STACK_H
#define STACK_H

#include <vector>
#include <cstddef>
#include <stdexcept>

class Stack {
public:
    Stack();

    void save();
    void restore();
    void reset();

    size_t getPosition() const;
    void advance();
    void retreat();

private:
    std::vector<size_t> stack;
    size_t current;
};

#endif
