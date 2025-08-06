#include "ParseOperator.h"
#include <unordered_map>
#include <string>

std::unordered_map<std::string, OperatorKind> operatorKindMap = {
    {"+", OperatorKind::Plus},
    {"-", OperatorKind::Minus},
    {"*", OperatorKind::Multiply},
    {"/", OperatorKind::Divide},
    {"=", OperatorKind::Equal},
    {"==", OperatorKind::Equal},
    {"!=", OperatorKind::NotEqual},
    {">", OperatorKind::Greater},
    {"<", OperatorKind::Less},
    {">=", OperatorKind::Greater},
    {"<=", OperatorKind::Less},
};

std::optional<Token> tokenizeOperator(Stream<char> &stream) {
    if (!stream.hasNext()) return std::nullopt;

    stream.save();
    size_t start = stream.position();

    std::string opLexeme;
    opLexeme += stream.current();

    if (operatorKindMap.find(opLexeme) != operatorKindMap.end()) {
        stream.advance();
        Token token(TokenType::Operator, opLexeme, start, stream.position());
        token.operatorKind = operatorKindMap[opLexeme];
        return token;
    }

    stream.restore();
    return std::nullopt;
}
