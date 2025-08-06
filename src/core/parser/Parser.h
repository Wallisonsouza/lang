#ifndef PARSER_H
#define PARSER_H

#include "../stream/Stream.h"
#include "../token/Token.h"
#include "../../core/ast/ASTnode.h"
#include <functional>
#include <optional>
#include <vector>
#include <algorithm>
#include <memory>

using ParserASTHandler = std::function<std::optional<std::unique_ptr<ASTNode>>(Stream<Token> &)>;

struct ParseHandler {
  int priority;
  ParserASTHandler fn;

  bool operator<(const ParseHandler &other) const {
    return priority > other.priority;
  }
};

class Parser {
public:
  Parser(const std::vector<Token> &tokens) : stream(tokens) {}

  void addHandler(int priority, ParserASTHandler fn) {
    handlers.push_back({priority, std::move(fn)});
    std::sort(handlers.begin(), handlers.end());
  }

  void parse() {
    while (stream.hasNext()) {
      bool matched = false;

      for (const auto &handler : handlers) {
        auto result = handler.fn(stream);
        if (result.has_value()) {
          ast.emplace_back(std::move(result.value()));
          matched = true;
          break;
        }
      }

      if (!matched) {
        stream.advance();
      }
    }
  }

  const std::vector<std::unique_ptr<ASTNode>> &getAST() const {
    return ast;
  }

private:
  Stream<Token> stream;
  std::vector<ParseHandler> handlers;
  std::vector<std::unique_ptr<ASTNode>> ast;
};

#endif
