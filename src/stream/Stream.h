#ifndef STREAM_H
#define STREAM_H

#include "../stack/Stack.h"
#include "IStream.h"
#include <stdexcept>
#include <vector>

template <typename T> class Stream : public IStream<T> {
public:
  Stream(const std::vector<T> &values) : values(values) {}

  T advance() override {
    if (!hasNext())
      throw std::out_of_range("End of stream");

    T val = values[stack.getPosition()];
    stack.advance();
    return val;
  }
 
  T current() const override {
    if (!hasNext())
      throw std::out_of_range("End of stream");
    return values[stack.getPosition()];
  }

  T previous() const override {
    size_t pos = stack.getPosition();
    if (pos == 0)
      throw std::out_of_range("No previous element");
    return values[pos - 1];
  }

  T peek(size_t offset = 0) const override {
    size_t target = stack.getPosition() + offset;
    if (target >= values.size())
      throw std::out_of_range("Peek out of range");
    return values[target];
  }

  bool hasNext() const override { return stack.getPosition() < values.size(); }

  void save() override { stack.save(); }

  void restore() override { stack.restore(); }

  void reset() override { stack.reset(); }

  size_t position() const override { return stack.getPosition(); }

private:
  std::vector<T> values;
  Stack stack;
};

#endif
