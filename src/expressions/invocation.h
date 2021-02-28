#pragma once

#include <string>

#include "expression.h"

class InvocationExpression: public Expression {
public:
    InvocationExpression(Expression* expression, const std::string& name);
    void accept(Visitor* visitor) override;

private:
    Expression* expression_;
    std::string name_;
};
