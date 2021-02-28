#pragma once

#include "expression.h"
#include "operators/operator.h"

class BinaryExpression: public Expression {
public:
    BinaryExpression(Expression* leftExpression, Expression* rightExpression, Operator* op);
    void accept(Visitor* visitor) override;

private:
    Expression* leftExpression_;
    Expression* rightExpression_;
    Operator* op_;
};
