#include "not.h"

NotExpression::NotExpression(Expression *expression):
        expression(expression) {}

void NotExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}