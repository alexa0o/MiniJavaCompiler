#pragma once

#include "expression.h"

class ThisExpression: public Expression {
public:
    ThisExpression();
    void accept(Visitor* visitor) override;
};