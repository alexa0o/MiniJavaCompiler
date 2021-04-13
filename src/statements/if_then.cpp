#include "if_then.h"

IfThenStatement::IfThenStatement(Expression *condition, Statement *statement):
        condition(condition), statement(statement) {}

void IfThenStatement::accept(Visitor *visitor) {
    visitor->visit(this);
}