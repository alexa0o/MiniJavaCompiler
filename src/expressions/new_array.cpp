#include "new_array.h"

NewArrayExpression::NewArrayExpression(TypeName type, Expression *size):
    type_(std::move(type)), size_(size) {}

void NewArrayExpression::accept(Visitor *visitor) {
    visitor->visit(this);
}