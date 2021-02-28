#pragma once

#include "statement.h"
#include "declarations.h"

class DeclarationStatement: public Statement {
public:
    DeclarationStatement(Declaration* declaration);
    void accept(Visitor* visitor) override;

private:
    Declaration* declaration_;
};

class VariableDeclarationAndAssignStatement: public Statement {
public:
    VariableDeclarationAndAssignStatement(const std::string& variable, Expression* expression);
    void accept(Visitor* visitor) override;

private:
    std::string variable_;
    Expression* expression_;
};