#pragma once

#include <string>

#include "expression.h"

class NewExpression: public Expression {
public:
    NewExpression(const std::string& typeName);
    void accept(Visitor* visitor) override;

private:
    std::string typeName_;
};

