#include <optional>
#include <unordered_set>
#include "../token/Token.h"
#include "../stream/Stream.h"

const std::unordered_set<std::string> keywords = {
    "const",
    "enum",
    "struct",
};

std::optional<Token> parseKeyword(Stream<char> &stream);