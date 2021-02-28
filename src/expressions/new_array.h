#pragma once

#include <string>

#include "expression.h"

class NewArrayExpression: public Expression {
public:
    NewArrayExpression(const std::string& typeName, Expression* size);
    void accept(Visitor* visitor) override;

private:
    std::string typeName_;
    Expression* size_;
};