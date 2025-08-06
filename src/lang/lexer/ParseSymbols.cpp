#include "ParseSymbols.h"
#include <unordered_map>

std::unordered_map<char, SymbolKind> symbolKindMap = {
    {':', SymbolKind::Colon},
    {'(', SymbolKind::OpenParen},
    {')', SymbolKind::CloseParen},
    {'{', SymbolKind::OpenBrace},
    {'}', SymbolKind::CloseBrace},
    {';', SymbolKind::Semicolon}
};

std::optional<Token> tokenizeSymbol(Stream<char> &stream) {
    if (!stream.hasNext()) return std::nullopt;

    stream.save();
    char current = stream.current();

    auto it = symbolKindMap.find(current);
    if (it != symbolKindMap.end()) {
        size_t start = stream.position();
        stream.advance();

        Token token(TokenType::Symbol, std::string(1, current), start, stream.position());
        token.symbolKind = it->second;

        return token;
    }

    stream.restore();
    return std::nullopt;
}
