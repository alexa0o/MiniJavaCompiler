#pragma once

#include "operator.h"

struct LTSOperator: Operator {
    int operator()(Expression* left, Expression* right) override;
};

