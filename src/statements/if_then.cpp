#include "if_then.h"

IfThenStatement::IfThenStatement(Expression *condition, Statement *statement):
    condition_(condition), statement_(statement) {}

void IfThenStatement::accept(Visitor *visitor) {}