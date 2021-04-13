#include "return.h"

ReturnStatement::ReturnStatement(Expression *expression):
        expression(expression) {}

void ReturnStatement::accept(Visitor* visitor) {
    visitor->visit(this);
}