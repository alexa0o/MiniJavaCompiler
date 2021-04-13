#include "dampersand.h"

int DAmpersandOperator::operator()(int left, int right) {
    return left && right;
}

std::string DAmpersandOperator::toString() const {
    return "&&";
}
