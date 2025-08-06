/* #include <memory>
#include <optional>
#include "../../core/ast/ASTnode.h"
#include "../../core/stream/Stream.h"
#include "./ParsePrimaryExpression.h"

int getPrecedence(const std::string &op) {
  if (op == "*" || op == "/") return 2;
  if (op == "+" || op == "-") return 1;
  return 0;
}

std::optional<std::unique_ptr<ASTNode>> parseExpression(Stream<Token>& stream, int parentPrecedence = 0) {
  auto left = parsePrimaryExpression(stream);
  if (!left) return std::nullopt;

  while (stream.hasNext()) {
    const Token& opToken = stream.peek();
    if (opToken.type != TokenType::Operator)
      break;

    int precedence = getPrecedence(opToken.lexeme);
    if (precedence < parentPrecedence)
      break;

    stream.advance(); 

    auto right = parseExpression(stream, precedence + 1);
    if (!right)
      return std::nullopt;

    left = std::make_unique<BinaryExpressionNode>(
      opToken.lexeme,
      std::move(*left),
      std::move(*right)
    );
  }

  return left;
}
 */