#include "statement_list.h"

void StatementList::addStatement(Statement *statement) {
    statements.push_back(statement);
}

void StatementList::accept(Visitor *visitor) {
    visitor->visit(this);
}