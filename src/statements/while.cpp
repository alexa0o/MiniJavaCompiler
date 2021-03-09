#include "while.h"

WhileStatement::WhileStatement(Expression *condition, Statement *statement):
        condition(condition), statement(statement) {}

void WhileStatement::accept(Visitor* visitor) {
    visitor->visit(this);
}