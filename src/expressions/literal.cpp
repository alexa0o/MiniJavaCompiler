#include "literal.h"


LiteralExpression::LiteralExpression(int value):
        value(value) {}

void LiteralExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}