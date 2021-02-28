#pragma once

#include "expressions/expression.h"

struct Operator {
    virtual int operator()(Expression* left, Expression* right) = 0;
};