#include "assign.h"

AssignStatement::AssignStatement(Expression* variable, Expression *expression):
    variable_(variable), expression_(expression) {}

void AssignStatement::accept(Visitor* visitor) {}