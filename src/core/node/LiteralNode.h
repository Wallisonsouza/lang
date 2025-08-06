#pragma once
#include "../ast/ASTnode.h"

class LiteralNode : public ASTNode {
public:
  std::string value;

  LiteralNode(std::string value) : value(std::move(value)) {}
};