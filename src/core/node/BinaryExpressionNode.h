#pragma once

#include "../ast/ASTnode.h"
#include <memory>

class BinaryExpressionNode : public ASTNode {
public:
  std::string op;
  std::unique_ptr<ASTNode> left;
  std::unique_ptr<ASTNode> right;

  BinaryExpressionNode(std::string op, std::unique_ptr<ASTNode> left,
                       std::unique_ptr<ASTNode> right)
      : op(std::move(op)), left(std::move(left)), right(std::move(right)) {}
};