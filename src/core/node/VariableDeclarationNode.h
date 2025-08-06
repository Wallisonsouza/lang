#ifndef VARIABLE_DECLARATION_NODE_H
#define VARIABLE_DECLARATION_NODE_H

#include <string>
#include "../ast/ASTnode.h"

struct VariableDeclarationNode : public ASTNode {
  std::string name;
  std::string typeName;
  std::string value;

  VariableDeclarationNode(const std::string &n, const std::string &t, const std::string &v) {
    type = ASTNodeType::VariableDeclaration;
    name = n;
    typeName = t;
    value = v;
  }
};

#endif
