#include "ParseType.h"

std::optional<Token> parseType(Stream<char> &stream) {
  size_t startPos = stream.position();
  std::string lexeme;

  stream.save();

  while (stream.hasNext() && std::isalpha(stream.current())) {
    lexeme += stream.advance();
  }

  if (lexeme.empty()) {
    stream.restore();
    return std::nullopt;
  }

  if (types.find(lexeme) != types.end()) {
    return Token(TokenType::Type, lexeme, startPos, stream.position());
  }

  stream.restore();
  return std::nullopt;
}