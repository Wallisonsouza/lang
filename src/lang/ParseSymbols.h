#include <string>
#include <unordered_set>
#include <optional>
#include "../token/Token.h"
#include "../stream/Stream.h"

const std::unordered_set<std::string> symbols = {
    ":",
    "=",
    "-",
};

std::optional<Token> parseSymbol(Stream<char> &stream);
