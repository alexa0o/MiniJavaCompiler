#include "println.h"

PrintlnStatement::PrintlnStatement(Expression *expression):
        expression(expression) {}

void PrintlnStatement::accept(Visitor *visitor) {
    visitor->visit(this);
}
