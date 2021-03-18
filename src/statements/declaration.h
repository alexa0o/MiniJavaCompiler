#pragma once

#include "type.h"
#include "statement.h"
#include "declarations.h"

class DeclarationStatement: public Statement {
public:
    DeclarationStatement(Declaration* declaration);
    void accept(Visitor* visitor) override;

    Declaration* declaration;
};

class VariableDeclarationAndAssignStatement: public Statement {
public:
    VariableDeclarationAndAssignStatement(SimpleType type, const std::string& variable, Expression* expression);
    void accept(Visitor* visitor) override;

    std::string variable;
    Expression* expression;
    SimpleType type;
};