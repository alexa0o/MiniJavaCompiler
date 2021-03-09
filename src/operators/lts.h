#pragma once

#include "operator.h"

struct LTSOperator: Operator {
    int operator()(int left, int right) override;
    std::string toString() const override;
};

