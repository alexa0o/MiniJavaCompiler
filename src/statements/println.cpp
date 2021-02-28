#include "println.h"

PrintlnStatement::PrintlnStatement(Expression *expression):
    expression_(expression) {}

void PrintlnStatement::accept(Visitor *visitor) {}
