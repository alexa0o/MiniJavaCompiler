#include "invocation.h"

InvocationStatement::InvocationStatement(Expression* invocationExpression):
    expression_(invocationExpression) {}

void InvocationStatement::accept(Visitor* visitor) {}