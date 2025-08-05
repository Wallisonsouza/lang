#include <string>
#include <unordered_set>
#include <optional>
#include "../token/Token.h"
#include "../stream/Stream.h"

const std::unordered_set<std::string> types = {
    "int",
    "float",
    "bool",
    "string"
};

std::optional<Token> parseType(Stream<char> &stream);