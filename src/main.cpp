#include "./core/lexer/Lexer.h"
#include "./core/token/Token.h"

#include "./lang/lexer/ParseNumber.h"
#include "./lang/lexer/ParseSymbols.h"
#include "./lang/lexer/PaserIdentifier.h"

#include "./lang/lexer/keyword/ParseKeyword.h"
#include "./lang/lexer/operator/ParseOperator.h"
#include "./lang/lexer/type/ParseType.h"

int main() {
  Lexer lexer("const age: int = 10");

  lexer.addHandler(0, tokenizeNumber);
  lexer.addHandler(1, tokenizeKeyword);
  lexer.addHandler(2, tokenizeType);
  lexer.addHandler(3, tokenizeIdentifier);
  lexer.addHandler(5, tokenizeOperator);
  lexer.addHandler(4, tokenizeSymbol);

  std::vector<Token> tokens = lexer.tokenize();

  for (const Token &tok : tokens) {
    tok.print();
  }

  return 0;
}
