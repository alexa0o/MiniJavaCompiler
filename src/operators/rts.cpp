#include "rts.h"

int RTSOperator::operator()(int left, int right) {
    return left > right;
}

std::string RTSOperator::toString() const {
    return ">";
}
