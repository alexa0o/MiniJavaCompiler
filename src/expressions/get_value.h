#pragma once

#include <string>

#include "expression.h"

class GetValueExpression: public Expression {
public:
    GetValueExpression(const std::string& variable);
    void accept(Visitor* visitor) override;

    std::string variable;
};