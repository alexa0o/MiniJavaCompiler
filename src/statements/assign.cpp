#include "assign.h"

AssignStatement::AssignStatement(Expression* variable, Expression *expression):
        variable(variable), expression(expression) {}

void AssignStatement::accept(Visitor* visitor) {
    visitor->visit(this);
}