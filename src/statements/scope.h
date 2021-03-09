#pragma once

#include "statement.h"
#include "statement_list.h"

class ScopeStatement: public Statement {
public:
    ScopeStatement(StatementList* statementList);
    void accept(Visitor* visitor) override;

    StatementList* statementList;
};