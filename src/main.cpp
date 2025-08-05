#include "./lexer/Lexer.h"
#include <iostream>
#include <string>

#include "./lang/ParseKeyword.h"
#include "./lang/ParseNumber.h"
#include "./lang/ParseSymbols.h"
#include "./lang/ParseType.h"
#include "./lang/PaserIdentifier.h"

int main() {
  Lexer lexer("const age: int = 10");

  lexer.addHandler(0, parseNumber);
  lexer.addHandler(1, parseKeyword);
  lexer.addHandler(2, parseIdentifier);
  lexer.addHandler(3, parseType);
  lexer.addHandler(4, parseSymbol);

  auto tokens = lexer.tokenize();

  for (auto &token : tokens) {
    std::cout << "{\n";
    std::cout << "  type: " << static_cast<int>(token.type) << "\n";
    std::cout << "  lexeme: " << token.lexeme << "\n";
    std::cout << "  start: " << token.start << "\n";
    std::cout << "  end: " << token.end << "\n";
    std::cout << "}\n";
  }

  return 0;
}