#pragma once

#include <string>

#include "type.h"
#include "expression.h"

class NewArrayExpression: public Expression {
public:
    NewArrayExpression(SimpleType type, Expression* size);
    void accept(Visitor* visitor) override;

private:
    SimpleType type_;
    Expression* size_;
};