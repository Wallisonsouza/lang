#include "ParseKeyword.h"
#include "ParseKeyword.h"
#include <unordered_map>

const std::unordered_map<std::string, KeywordKind> keywordKindMap = {
    {"const", KeywordKind::Const},
    {"enum", KeywordKind::Enum},
    {"struct", KeywordKind::Struct},
};

static inline bool isLowercaseAZ(char charTest) {
  return (charTest >= 'a' && charTest <= 'z');
}

std::optional<Token> tokenizeKeyword(Stream<char> &stream) {
  if (!stream.hasNext()) return std::nullopt;
  if (!isLowercaseAZ(stream.current())) return std::nullopt;

  stream.save();
  size_t startPos = stream.position();
  std::string lexeme;

  while (stream.hasNext() && isLowercaseAZ(stream.current())) {
    lexeme += stream.advance();
  }

  auto it = keywordKindMap.find(lexeme);
  if (it != keywordKindMap.end()) {
    Token token(TokenType::Keyword, lexeme, startPos, stream.position());
    token.keywordKind = it->second;
    return token;
  }

  stream.restore();
  return std::nullopt;
}
