#pragma once

#include "operator.h"

struct RTSOperator: Operator {
    int operator()(int left, int right) override;
    std::string toString() const override;
};

