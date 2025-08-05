#include "../stream/Stream.h"
#include "../token/Token.h"
#include <optional>

std::optional<Token> parseIdentifier(Stream<char> &stream);
