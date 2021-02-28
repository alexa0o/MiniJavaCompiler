#include "not.h"

NotExpression::NotExpression(Expression *expression):
    expression_(expression) {}

void NotExpression::accept(Visitor* visitor) {}