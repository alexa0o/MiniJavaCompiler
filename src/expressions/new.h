#pragma once

#include <string>

#include "type.h"
#include "expression.h"

class NewExpression: public Expression {
public:
    NewExpression(SimpleType type);
    void accept(Visitor* visitor) override;

private:
    SimpleType type_;
};

