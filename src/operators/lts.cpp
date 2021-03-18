#include "lts.h"

int LTSOperator::operator()(int left, int right) {
    return left < right;
}

std::string LTSOperator::toString() const {
    return "<";
}
