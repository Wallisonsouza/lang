#pragma once
#include "../ast/ASTnode.h"

class IdentifierNode : public ASTNode {
public:
  std::string name;

  IdentifierNode(std::string name) : name(std::move(name)) {}
};