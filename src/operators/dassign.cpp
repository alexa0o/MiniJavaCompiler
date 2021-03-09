#include "dassign.h"

int DAssignOperator::operator()(int left, int right) {
    return left == right;
}

std::string DAssignOperator::toString() const {
    return "==";
}
