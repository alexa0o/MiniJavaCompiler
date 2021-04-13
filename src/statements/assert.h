#pragma once

#include "statement.h"

class AssertStatement: public Statement {
public:
    AssertStatement(Expression* expression);
    void accept(Visitor* visitor) override;

    Expression* expression;
};
