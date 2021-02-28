#include "length.h"

LengthExpression::LengthExpression(Expression *expression):
    expression_(expression) {}

void LengthExpression::accept(Visitor* visitor) {}