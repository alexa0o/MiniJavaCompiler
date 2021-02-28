#pragma once

#include "statement.h"

class PrintlnStatement: public Statement {
public:
    PrintlnStatement(Expression* expression);
    void accept(Visitor* visitor) override;

    Expression* expression_;
};