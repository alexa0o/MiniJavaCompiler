#pragma once

#include <string>

#include "expression.h"

class LValueExpression : public Expression {
public:
    LValueExpression(const std::string& identifier, Expression* index = nullptr);
    void accept(Visitor* visitor) override;

    std::string identifier;
    Expression* index;
};