#pragma once

#include "operator.h"

struct DAssignOperator: Operator {
    int operator()(Expression* left, Expression* right) override;
};

