#pragma once

#include "expression.h"

class LengthExpression: public Expression {
public:
    LengthExpression(Expression* expression);
    void accept(Visitor* visitor) override;

private:
    Expression* expression_;
};
