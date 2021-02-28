#include "scope.h"

ScopeStatement::ScopeStatement(StatementList* statementList):
    statementList_(statementList) {}

void ScopeStatement::accept(Visitor *visitor) {}