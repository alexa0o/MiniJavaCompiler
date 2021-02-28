#include "assert.h"

AssertStatement::AssertStatement(Expression *expression): expression_(expression) {}

void AssertStatement::accept(Visitor* visitor) {}