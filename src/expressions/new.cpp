#include "new.h"

NewExpression::NewExpression(const std::string &typeName):
    typeName_(typeName) {}

void NewExpression::accept(Visitor* visitor) {}