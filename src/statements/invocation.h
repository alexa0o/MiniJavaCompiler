#pragma once

#include <string>

#include "statement.h"

class InvocationStatement: public Statement {
public:
    InvocationStatement(Expression* expression, const std::string& method);
    void accept(Visitor* visitor) override;

private:
    Expression* expression_;
    std::string method_;
};

