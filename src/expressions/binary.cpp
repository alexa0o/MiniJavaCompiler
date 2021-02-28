#include "binary.h"

BinaryExpression::BinaryExpression(Expression *leftExpression, Expression *rightExpression, Operator *op):
    leftExpression_(leftExpression), rightExpression_(rightExpression), op_(op) {}

void BinaryExpression::accept(Visitor* visitor) {}