#pragma once

#include <string>

#include "type.h"
#include "expression.h"

class NewArrayExpression: public Expression {
public:
    NewArrayExpression(TypeName type, Expression* size);
    void accept(Visitor* visitor) override;

private:
    TypeName type_;
    Expression* size_;
};