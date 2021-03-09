#include "new.h"

NewExpression::NewExpression(Type type):
    type_(std::move(type)) {}

void NewExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}