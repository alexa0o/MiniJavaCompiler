#include "access.h"

AccessExpression::AccessExpression(Expression *expression, Expression *index):
    expression_(expression), index_(index) {}

void AccessExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}