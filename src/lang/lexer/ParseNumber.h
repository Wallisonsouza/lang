#include <optional>
#include "../../core/token/Token.h"
#include "../../core/stream/Stream.h"

std::optional<Token> tokenizeNumber(Stream<char> &stream);