#include <optional>
#include <unordered_set>
#include "../../../core/token/Token.h"
#include "../../../core/stream/Stream.h"

std::optional<Token> tokenizeKeyword(Stream<char> &stream);