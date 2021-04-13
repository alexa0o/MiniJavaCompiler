#include "minus.h"

int MinusOperator::operator()(int left, int right) {
    return left - right;
}

std::string MinusOperator::toString() const {
    return "-";
}
