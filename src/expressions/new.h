#pragma once

#include <string>

#include "type.h"
#include "expression.h"

class NewExpression: public Expression {
public:
    NewExpression(Type type);
    void accept(Visitor* visitor) override;

private:
    Type type_;
};

