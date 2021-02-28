#pragma once

#include "operator.h"

struct DPipeOperator: Operator {
    int operator()(Expression* left, Expression* right) override;
};

