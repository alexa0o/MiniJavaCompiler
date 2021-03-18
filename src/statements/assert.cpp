#include "assert.h"

AssertStatement::AssertStatement(Expression *expression): expression(expression) {}

void AssertStatement::accept(Visitor* visitor) {}