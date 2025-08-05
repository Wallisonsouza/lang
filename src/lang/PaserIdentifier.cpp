#include "PaserIdentifier.h"

std::optional<Token> parseIdentifier(Stream<char> &stream) {
  size_t startPos = stream.position();
  std::string lexeme;

  if (!stream.hasNext()) {
    return std::nullopt;
  }

  // match = ( _ or a-Z)
  char first = stream.current();
  if (std::isalpha(first) || first == '_') {
    lexeme += stream.advance();
  } else {
    return std::nullopt;
  }

  // match = ( _ or a-Z or 0-9)
  while (stream.hasNext()) {
    char c = stream.current();
    if (std::isalnum(c) || c == '_') {
      lexeme += stream.advance();
    } else {
      break;
    }
  }

  return Token(TokenType::Identifier, lexeme, startPos, stream.position());
}
