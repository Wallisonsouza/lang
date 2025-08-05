#include "ParseSymbols.h"

std::optional<Token> parseSymbol(Stream<char> &stream) {
    size_t startPos = stream.position();

    auto current = stream.current();

    stream.save();
    stream.advance();

   if (symbols.find(&current) != symbols.end()) {
    return Token(TokenType::Keyword, &current, startPos, stream.position());
  }

  stream.restore();

  return std::nullopt;
  stream.save();
}
