#include "invocation.h"

InvocationStatement::InvocationStatement(Expression* expression, const std::string& method):
    expression_(expression), method_(method) {}

void InvocationStatement::accept(Visitor* visitor) {}