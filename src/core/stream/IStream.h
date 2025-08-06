#ifndef ISTREAM_H
#define ISTREAM_H

#include <cstddef>

template <typename T> class IStream {
public:
  virtual ~IStream() = default;

  virtual T advance() = 0;
  virtual T current() const = 0;
  virtual T next() const = 0;
  virtual T previous() const = 0;
  virtual const T& peek(size_t offset = 0) const = 0;

  virtual bool hasNext() const = 0;

  virtual void save() = 0;
  virtual void restore() = 0;
  virtual void reset() = 0;

  virtual size_t position() const = 0;
};

#endif
