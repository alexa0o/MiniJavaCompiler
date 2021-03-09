#pragma once

#include "expression.h"


class LiteralExpression: public Expression {
public:
    LiteralExpression(int value);
    void accept(Visitor* visitor) override;

    int value;
};
