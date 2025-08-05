#pragma once

#include <cstddef>
#include <string>

enum class TokenType { 
    Number, 
    Identifier, 
    Symbol, 
    Unknown, 
    EndOfFile 
};

enum class TokenSubType {
    FunctionCall,
    FunctionParamenter,
    FunctioType

};

struct Token {
  TokenType type;
  TokenSubType subType;
  std::string lexeme;
  size_t position;

  Token(TokenType t, std::string lex, size_t pos)
      : type(t), lexeme(std::move(lex)), position(pos) {}
};
