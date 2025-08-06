/* #pragma once

#include <memory>
#include <optional>

#include "../../core/ast/ASTnode.h"
#include "../../core/node/IdentifierNode.h"
#include "../../core/node/LiteralNode.h"
#include "../../core/stream/Stream.h"
#include "../config/LanguageConfig.h"

std::optional<std::unique_ptr<ASTNode>> parseExpression(Stream<Token> &stream);

std::optional<std::unique_ptr<ASTNode>>
parsePrimaryExpression(Stream<Token> &stream) {
  if (!stream.hasNext())
    return std::nullopt;
  const Token &tok = stream.peek();

  if (tok.type == TokenType::Symbol && tok.symbolKind == SymbolKind::Comma) {
    stream.advance();

    auto expr = parseExpression(stream);
    if (!expr)
      return std::nullopt;

    if (!stream.match(TokenType::Symbol, LanguageConfig::closeParen)) {
      return std::nullopt;
    }

    return expr;
  }

  if (tok.type == TokenType::Literal) {
    stream.advance();
    return std::make_unique<LiteralNode>(tok.lexeme);
  }

  if (tok.type == TokenType::Identifier) {
    stream.advance();
    return std::make_unique<IdentifierNode>(tok.lexeme);
  }

  return std::nullopt;
}
 */