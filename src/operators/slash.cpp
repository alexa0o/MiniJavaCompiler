#include "slash.h"

int SlashOperator::operator()(int left, int right) {
    return left / right;
}

std::string SlashOperator::toString() const {
    return "/";
}
