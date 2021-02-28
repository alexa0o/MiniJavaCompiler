#pragma once

#include "operator.h"

struct PercentOperator: Operator {
    int operator()(Expression* left, Expression* right) override;
};

