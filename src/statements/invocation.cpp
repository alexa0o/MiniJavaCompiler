#include "invocation.h"

InvocationStatement::InvocationStatement(Expression* invocationExpression):
        expression(invocationExpression) {}

void InvocationStatement::accept(Visitor* visitor) {
    visitor->visit(this);
}