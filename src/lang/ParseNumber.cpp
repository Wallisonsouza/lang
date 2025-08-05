#include "ParseNumber.h"

std::optional<Token> parseNumber(Stream<char> &stream) {
  size_t startPos = stream.position();
  std::string lexeme;

  while (stream.hasNext() && std::isdigit(stream.current())) {
    lexeme += stream.advance();
  }

  if (!lexeme.empty()) {
    return Token(TokenType::Number, lexeme, startPos, stream.position());
  }

  return std::nullopt;
}
