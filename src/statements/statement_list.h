#pragma once

#include <vector>

#include "statement.h"

class StatementList: public BaseElement {
public:
    void addStatement(Statement* statement);
    void accept(Visitor* visitor) override;

    std::vector<Statement*> statements_;
};

