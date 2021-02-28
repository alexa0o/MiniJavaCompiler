#pragma once

#include <string>

#include "statement.h"
#include "expressions/expression.h"

class InvocationStatement: public Statement {
public:
    InvocationStatement(Expression* invocationExpression);
    void accept(Visitor* visitor) override;

private:
    Expression* expression_;
};

