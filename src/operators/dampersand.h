#pragma once

#include "operator.h"

struct DAmpersandOperator: Operator {
    int operator()(int left, int right) override;
    std::string toString() const override;
};

