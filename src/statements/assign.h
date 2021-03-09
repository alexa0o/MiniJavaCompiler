#pragma once

#include <string>

#include "statement.h"

class AssignStatement: public Statement {
public:
    AssignStatement(Expression* variable, Expression* expression);
    void accept(Visitor* visitor) override;

    Expression* variable;
    Expression* expression;
};
