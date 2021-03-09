#include "binary.h"

BinaryExpression::BinaryExpression(Expression *leftExpression, Expression *rightExpression, Operator *op):
        leftExpression(leftExpression), rightExpression(rightExpression), op(op) {}

void BinaryExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}