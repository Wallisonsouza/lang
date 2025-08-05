#pragma once

#include <cstddef>
#include <string>

enum class TokenType { 
    Number, 
    Type,
    Keyword,
    Identifier, 
    Symbol, 
    Unknown, 
    EndOfFile 
};

struct Token {
  TokenType type;
  std::string lexeme;
  size_t end;
  size_t start;

  Token(TokenType token, std::string lexeme, size_t start, size_t end)
      : type(token), lexeme(std::move(lexeme)), end(end), start(start) {}
};
