#include <optional>
#include "../token/Token.h"
#include "../stream/Stream.h"

// identificadores devem vir uma layer antes de number
std::optional<Token> parseNumber(Stream<char> &stream);
