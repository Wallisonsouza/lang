#include "ParseKeyword.h"

std::optional<Token> parseKeyword(Stream<char> &stream) {
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

  if (keywords.find(lexeme) != keywords.end()) {
    return Token(TokenType::Keyword, lexeme, startPos, stream.position());
  }

  stream.restore();
  return std::nullopt;
}