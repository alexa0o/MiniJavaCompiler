#pragma once

#include "statement.h"

class IfThenElseStatement: public Statement {
public:
    IfThenElseStatement(Expression* condition, Statement* thenStatement, Statement* elseStatement);
    void accept(Visitor* visitor) override;

    Expression* condition;
    Statement* thenStatement;
    Statement* elseStatement;
};
