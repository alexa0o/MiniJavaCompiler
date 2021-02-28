#pragma once

#include "operator.h"

struct RTSOperator: Operator {
    int operator()(Expression* left, Expression* right) override;
};

