#ifndef SYMBOL_PARSER_H
#define SYMBOL_PARSER_H

#include <unordered_set>
#include <optional>
#include "../../core/token/Token.h"
#include "../../core/stream/Stream.h"

extern std::unordered_set<char> symbols;
std::optional<Token> tokenizeSymbol(Stream<char> &stream);

#endif
