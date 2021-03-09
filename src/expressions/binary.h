#pragma once

#include "expression.h"
#include "operators/operator.h"

class BinaryExpression: public Expression {
public:
    BinaryExpression(Expression* leftExpression, Expression* rightExpression, Operator* op);
    void accept(Visitor* visitor) override;

    Expression* leftExpression;
    Expression* rightExpression;
    Operator* op;
};
