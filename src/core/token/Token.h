#pragma once

#include <cstddef>
#include <optional>
#include <string>

enum class TokenType {
  Literal,
  Operator,
  Type,
  FunctionType,
  IdentifierType,
  Keyword,
  Identifier,
  Symbol,
  Unknown,
  EndOfFile
};

enum class KeywordKind {
  Const,
  Let,
  Enum,
  Struct,
  If,
  Else,
  Return,
  While,
  For,

};

enum class LiteralKind {
  Number,
  String,
  Boolean,
  Null,

};

enum class OperatorKind {
  Plus,
  Minus,
  Multiply,
  Divide,
  Equal,
  NotEqual,
  Greater,
  Less,

};

enum class TypeKind { Int, Float, Bool, String };

enum class SymbolKind {
  OpenParen,
  CloseParen,
  OpenBrace,
  CloseBrace,
  Colon,
  Semicolon,
  Comma,

};

#include <iostream>

struct Token {
  TokenType type;
  std::string lexeme;
  size_t start;
  size_t end;

  std::optional<KeywordKind> keywordKind;
  std::optional<LiteralKind> literalKind;
  std::optional<OperatorKind> operatorKind;
  std::optional<SymbolKind> symbolKind;
  std::optional<TypeKind> typeKind;
  std::optional<std::string> scope;

  Token(TokenType tokenType, std::string lex, size_t s, size_t e)
      : type(tokenType), lexeme(std::move(lex)), start(s), end(e) {}

 void print() const {
    std::cout << "Token: " << lexeme << ", Type: ";
    switch (type) {
        case TokenType::Literal:   std::cout << "Literal"; break;
        case TokenType::Operator:  std::cout << "Operator"; break;
        case TokenType::Type:      std::cout << "Type"; break;
        case TokenType::FunctionType: std::cout << "FunctionType"; break;
        case TokenType::IdentifierType: std::cout << "IdentifierType"; break;
        case TokenType::Keyword:   std::cout << "Keyword"; break;
        case TokenType::Identifier: std::cout << "Identifier"; break;
        case TokenType::Symbol:    std::cout << "Symbol"; break;
        case TokenType::Unknown:   std::cout << "Unknown"; break;
        case TokenType::EndOfFile: std::cout << "EndOfFile"; break;
    }

    if (keywordKind) {
        std::cout << " (";
        switch (*keywordKind) {
            case KeywordKind::Const: std::cout << "Const"; break;
            case KeywordKind::Let: std::cout << "Let"; break;
            case KeywordKind::If: std::cout << "If"; break;
            case KeywordKind::Else: std::cout << "Else"; break;
            case KeywordKind::Return: std::cout << "Return"; break;
            case KeywordKind::While: std::cout << "While"; break;
            case KeywordKind::For: std::cout << "For"; break;
            case KeywordKind::Struct: std::cout << "Struct"; break;
            case KeywordKind::Enum: std::cout << "Enum"; break;
        }
        std::cout << ")";
    } else if (literalKind) {
        std::cout << " (";
        switch (*literalKind) {
            case LiteralKind::Number: std::cout << "Number"; break;
            case LiteralKind::String: std::cout << "String"; break;
            case LiteralKind::Boolean: std::cout << "Boolean"; break;
            case LiteralKind::Null: std::cout << "Null"; break;
        }
        std::cout << ")";
    } else if (operatorKind) {
        std::cout << " (";
        switch (*operatorKind) {
            case OperatorKind::Plus: std::cout << "Plus"; break;
            case OperatorKind::Minus: std::cout << "Minus"; break;
            case OperatorKind::Multiply: std::cout << "Multiply"; break;
            case OperatorKind::Divide: std::cout << "Divide"; break;
            case OperatorKind::Equal: std::cout << "Equal"; break;
            case OperatorKind::NotEqual: std::cout << "NotEqual"; break;
            case OperatorKind::Greater: std::cout << "Greater"; break;
            case OperatorKind::Less: std::cout << "Less"; break;
        }
        std::cout << ")";
    } else if (symbolKind) {
        std::cout << " (";
        switch (*symbolKind) {
            case SymbolKind::OpenParen: std::cout << "OpenParen"; break;
            case SymbolKind::CloseParen: std::cout << "CloseParen"; break;
            case SymbolKind::OpenBrace: std::cout << "OpenBrace"; break;
            case SymbolKind::CloseBrace: std::cout << "CloseBrace"; break;
            case SymbolKind::Colon: std::cout << "Colon"; break;
            case SymbolKind::Semicolon: std::cout << "Semicolon"; break;
            case SymbolKind::Comma: std::cout << "Comma"; break;
        }
        std::cout << ")";
    } else if (typeKind) {
        std::cout << " (";
        switch (*typeKind) {
            case TypeKind::Int: std::cout << "Int"; break;
            case TypeKind::Float: std::cout << "Float"; break;
            case TypeKind::Bool: std::cout << "Bool"; break;
            case TypeKind::String: std::cout << "String"; break;
        }
        std::cout << ")";
    }

    std::cout << ", Start: " << start << ", End: " << end << "\n";
}

};