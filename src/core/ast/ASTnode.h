#ifndef ASTNODE_H
#define ASTNODE_H

#include <string>

enum class ASTNodeType {
  VariableDeclaration,
  FunctionDefinition,
  TypeDefinition,
  BinaryExpression,
  Literal,
  Identifier,
 
};

struct ASTNode {
  ASTNodeType type;
  virtual ~ASTNode() = default;
};

#endif