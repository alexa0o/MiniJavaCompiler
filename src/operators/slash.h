#pragma once

#include "operator.h"

struct SlashOperator: Operator {
    int operator()(Expression* left, Expression* right) override;
};

