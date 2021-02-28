#pragma once

#include "operator.h"

struct DAmpersandOperator: Operator {
    int operator()(Expression* left, Expression* right) override;
};

