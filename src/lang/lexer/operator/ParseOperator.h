#pragma once

#include <unordered_set>
#include <optional>
#include "../../../core/token/Token.h"
#include "../../../core/stream/Stream.h"

extern std::unordered_set<char> symbols;
std::optional<Token> tokenizeOperator(Stream<char> &stream);