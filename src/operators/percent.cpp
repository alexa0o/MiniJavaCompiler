#include "percent.h"

int PercentOperator::operator()(int left, int right) {
    return left % right;
}

std::string PercentOperator::toString() const {
    return "%";
}
