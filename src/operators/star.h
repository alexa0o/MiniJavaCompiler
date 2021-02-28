#pragma once

#include "operator.h"

struct StarOperator: Operator {
    int operator()(Expression* left, Expression* right) override;
};

