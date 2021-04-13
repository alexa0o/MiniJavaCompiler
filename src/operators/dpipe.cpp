#include "dpipe.h"

int DPipeOperator::operator()(int left, int right) {
    return left || right;
}

std::string DPipeOperator::toString() const {
    return "||";
}
