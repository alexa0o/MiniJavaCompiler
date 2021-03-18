#pragma once

#include "expression.h"

class AccessExpression: public Expression {
public:
    AccessExpression(Expression* expression, Expression* index);
    void accept(Visitor* visitor) override;

    Expression* expression_;
    Expression* index_;
};

