#pragma once

#include <string>

#include "type.h"
#include "expression.h"

class NewExpression: public Expression {
public:
    NewExpression(TypeName type);
    void accept(Visitor* visitor) override;

private:
    TypeName type_;
};

