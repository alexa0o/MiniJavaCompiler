#include "star.h"

int StarOperator::operator()(int left, int right) {
    return left * right;
}

std::string StarOperator::toString() const {
    return "*";
}
