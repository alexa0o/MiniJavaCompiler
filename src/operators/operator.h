#pragma once

#include <string>

#include "expressions/expression.h"

struct Operator {
    virtual int operator()(int left, int right) = 0;
    virtual std::string toString() const = 0;
};