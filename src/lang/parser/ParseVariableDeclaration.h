/* #include <memory>
#include <optional>

#include "../../core/ast/ASTnode.h"
#include "../../core/stream/Stream.h"
#include "../../core/token/Token.h"
#include "../config/LanguageConfig.h"
#include "../../core/node/VariableDeclarationNode.h"

struct Guard {
  Stream<Token> &s;
  bool active = true;
  Guard(Stream<Token> &s) : s(s) { s.save(); }
  ~Guard() {
    if (active)
      s.restore();
  }
  void cancel() { active = false; }
};


std::optional<std::unique_ptr<ASTNode>>
parseVariableDeclaration(Stream<Token> &stream) {
  Guard guard(stream);

  auto expect = [&](TokenType expectedType) -> std::optional<Token> {
    if (!stream.hasNext())
      return std::nullopt;
    const Token &t = stream.peek();
    if (t.type != expectedType)
      return std::nullopt;
    stream.advance();
    return t;
  };

  if (!stream.match(TokenType::Keyword, LanguageConfig::keywordConst))
    return std::nullopt;

  std::optional<Token> name = expect(TokenType::Identifier);
  if (!name)
    return std::nullopt;

  if (!stream.match(TokenType::Symbol, LanguageConfig::typeSeparator))
    return std::nullopt;

  std::optional<Token> type = expect(TokenType::Type);
  if (!type)
    return std::nullopt;

  if (!stream.match(TokenType::Symbol, LanguageConfig::assignment))
    return std::nullopt;

  std::optional<Token> value = expect(TokenType::Number);
  if (!value)
    return std::nullopt;

  auto node = std::make_unique<VariableDeclarationNode>(
      name->lexeme, type->lexeme, value->lexeme);

  guard.cancel();
  return node;
} */