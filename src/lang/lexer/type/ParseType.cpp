#include "ParseType.h"
#include <unordered_map>


const std::unordered_map<std::string, TypeKind> typeKindMap = {
    {"int", TypeKind::Int},
    {"float", TypeKind::Float},
    {"bool", TypeKind::Bool},
    {"string", TypeKind::String}
};

std::optional<Token> tokenizeType(Stream<char> &stream) {
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

  auto it = typeKindMap.find(lexeme);
  if (it != typeKindMap.end()) {
    Token token(TokenType::Type, lexeme, startPos, stream.position());
    token.typeKind = it->second;
    return token;
  }

  stream.restore();
  return std::nullopt;
}
