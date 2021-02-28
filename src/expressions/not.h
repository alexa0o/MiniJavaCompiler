#pragma once

#include "expression.h"

class NotExpression: public Expression {
public:
    NotExpression(Expression* expression);
    void accept(Visitor* visitor) override;

private:
    Expression* expression_;
};
