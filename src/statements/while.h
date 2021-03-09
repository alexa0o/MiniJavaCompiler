#pragma once

#include "statement.h"

class WhileStatement: public Statement {
public:
    WhileStatement(Expression* condition, Statement* statement);
    void accept(Visitor* visitor) override;

    Expression* condition;
    Statement* statement;
};
