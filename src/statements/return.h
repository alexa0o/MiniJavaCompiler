#pragma once

#include "statement.h"

class ReturnStatement: public Statement {
public:
    ReturnStatement(Expression* expression);
    void accept(Visitor* visitor) override;

    Expression* expression;
};

