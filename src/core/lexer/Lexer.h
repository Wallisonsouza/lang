#ifndef LEXER_H
#define LEXER_H

#include "../stream/Stream.h"
#include "../token/Token.h"
#include <algorithm>
#include <cctype>
#include <functional>
#include <map>
#include <optional>
#include <string>
#include <vector>

using TokenHandler = std::function<std::optional<Token>(Stream<char>&)>;

struct Handler {
  int priority;
  TokenHandler fn;

  bool operator<(const Handler& other) const {
    return priority < other.priority;
  }
};

class Lexer {
public:
  Lexer(const std::string& source)
      : stream(std::vector<char>(source.begin(), source.end())) {}

  void addHandler(int priority, TokenHandler fn) {
    handlers.push_back({priority, std::move(fn)});
    sorted = false;
  }

  std::vector<Token> tokenize() {
    if (!sorted) {
      std::stable_sort(handlers.begin(), handlers.end());
      sorted = true;
    }

    std::vector<Token> tokens;

    while (stream.hasNext()) {
      skipWhitespace();

      bool matched = false;

      for (const auto& handler : handlers) {
        auto result = handler.fn(stream);
        if (result.has_value()) {
          tokens.push_back(result.value());
          matched = true;
          break;
        }
      }

      if (!matched) {
        stream.advance();
      }
    }

    tokens.emplace_back(TokenType::EndOfFile, "/0", stream.position(), stream.position());

    return tokens;
  }

private:
  Stream<char> stream;
  std::vector<Handler> handlers;
  bool sorted = false;

  void skipWhitespace() {
    while (stream.hasNext() && std::isspace(stream.current())) {
      stream.advance();
    }
  }
};

#endif
