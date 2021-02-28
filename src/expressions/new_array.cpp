#include "new_array.h"

NewArrayExpression::NewArrayExpression(Type type, Expression *size):
    type_(std::move(type)), size_(size) {}

void NewArrayExpression::accept(Visitor *visitor) {}