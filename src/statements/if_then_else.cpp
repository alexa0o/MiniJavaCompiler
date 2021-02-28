#include "if_then_else.h"

IfThenElseStatement::IfThenElseStatement(Expression *condition, Statement *thenStatement, Statement *elseStatement):
    condition_(condition), thenStatement_(thenStatement), elseStatement_(elseStatement) {}

void IfThenElseStatement::accept(Visitor* visitor) {}