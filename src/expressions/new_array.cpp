#include "new_array.h"

NewArrayExpression::NewArrayExpression(const std::string &typeName, Expression *size):
    typeName_(typeName), size_(size) {}

void NewArrayExpression::accept(Visitor *visitor) {}