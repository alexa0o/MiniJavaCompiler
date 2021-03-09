#pragma once

#include "operator.h"

struct PlusOperator: Operator {
    int operator()(int left, int right) override;
    std::string toString() const override;
};

