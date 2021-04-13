#include "new.h"

NewExpression::NewExpression(TypeName type):
    type_(std::move(type)) {}

void NewExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}