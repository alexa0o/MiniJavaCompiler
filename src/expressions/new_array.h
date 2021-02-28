#pragma once

#include <string>

#include "type.h"
#include "expression.h"

class NewArrayExpression: public Expression {
public:
    NewArrayExpression(Type type, Expression* size);
    void accept(Visitor* visitor) override;

private:
    Type type_;
    Expression* size_;
};