#pragma once

#include "operator.h"

struct PlusOperator: Operator {
    int operator()(Expression* left, Expression* right) override;
};

