#pragma once

#include "operator.h"

struct MinusOperator: Operator {
    int operator()(Expression* left, Expression* right) override;
};

