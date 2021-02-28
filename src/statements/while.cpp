#include "while.h"

WhileStatement::WhileStatement(Expression *condition, Statement *statement):
    condition_(condition), statement_(statement) {}

void WhileStatement::accept(Visitor* visitor) {}