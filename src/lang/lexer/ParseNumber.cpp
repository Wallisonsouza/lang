#include "ParseNumber.h"

std::optional<Token> tokenizeNumber(Stream<char> &stream) {
    size_t startPos = stream.position();
    std::string lexeme;

    while (stream.hasNext() && std::isdigit(stream.current())) {
        lexeme += stream.advance();
    }

    if (!lexeme.empty()) {
        Token token(TokenType::Literal, lexeme, startPos, stream.position());
        token.literalKind = LiteralKind::Number;
        return token;
    }

    return std::nullopt;
}