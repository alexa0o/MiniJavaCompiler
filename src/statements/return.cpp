#include "return.h"

ReturnStatement::ReturnStatement(Expression *expression):
    expression_(expression) {}

void ReturnStatement::accept(Visitor* visitor) {}