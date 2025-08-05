#ifndef LEXER_H
#define LEXER_H

#include "../stream/Stream.h"
#include <cctype> 
#include <functional>
#include <map>
#include <optional>
#include <string>
#include <vector>
#include "../token/Token.h"

using TokenHandler = std::function<std::optional<Token>(Stream<char> &)>;

class Lexer {
public:
  Lexer(const std::string &source)
      : stream(std::vector<char>(source.begin(), source.end())) {}

  void addHandler(int layer, TokenHandler handler) {
    tokenLayers[layer].push_back(handler);
  }

  std::vector<Token> tokenize() {
    std::vector<Token> tokens;

    while (stream.hasNext()) {
      skipWhitespace();

      bool matched = false;

      for (auto &[layer, handlers] : tokenLayers) {
        for (auto &handler : handlers) {
          auto result = handler(stream);
          if (result.has_value()) {
            tokens.push_back(result.value());
            matched = true;
            break;
          }
        }
        if (matched)
          break;
      }

      if (!matched) {
        stream.advance();
      }
    }
    return tokens;
  }

private:
  Stream<char> stream;
  std::map<int, std::vector<TokenHandler>> tokenLayers;

  void skipWhitespace() {
    while (stream.hasNext() && std::isspace(stream.current()))
      stream.advance();
  }
};

#endif 
