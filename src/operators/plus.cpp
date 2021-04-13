#include "plus.h"

int PlusOperator::operator()(int left, int right) {
    return left + right;
}

std::string PlusOperator::toString() const {
    return "+";
}
