#include "if_then_else.h"

IfThenElseStatement::IfThenElseStatement(Expression *condition, Statement *thenStatement, Statement *elseStatement):
        condition(condition), thenStatement(thenStatement), elseStatement(elseStatement) {}

void IfThenElseStatement::accept(Visitor* visitor) {
    visitor->visit(this);
}