#include "scope.h"

ScopeStatement::ScopeStatement(StatementList* statementList):
        statementList(statementList) {}

void ScopeStatement::accept(Visitor *visitor) {
    visitor->visit(this);
}