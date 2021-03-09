#pragma once

#include "statement.h"

class IfThenStatement: public Statement {
public:
    IfThenStatement(Expression* condition, Statement* statement);
    void accept(Visitor* visitor) override;

    Expression* condition;
    Statement* statement;
};

