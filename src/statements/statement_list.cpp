#include "statement_list.h"

void StatementList::addStatement(Statement *statement) {
    statements_.push_back(statement);
}

void StatementList::accept(Visitor *visitor) {}