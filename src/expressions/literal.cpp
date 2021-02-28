#include "literal.h"


LiteralExpression::LiteralExpression(int value):
    value_(value) {}

void LiteralExpression::accept(Visitor* visitor) {}