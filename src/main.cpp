#include "./lexer/Lexer.h"
#include <iostream>

std::optional<Token> parseNumber(Stream<char> &stream) {
  size_t startPos = stream.position();
  std::string lexeme;

  while (stream.hasNext() && std::isdigit(stream.next())) {
    lexeme += stream.advance();
  }

  if (!lexeme.empty()) {
    return Token(TokenType::Number, lexeme, startPos);
  }

  return std::nullopt;
}


int main() {
    Lexer lexer("123 abc + 456");
    lexer.addHandler(1, parseNumber);
    auto tokens = lexer.tokenize();

    for (auto& token : tokens) {
        std::cout << "Token: " << token.lexeme << " at " << token.position << "\n";
    }

    return 0;
}
