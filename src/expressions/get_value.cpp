#include "get_value.h"

GetValueExpression::GetValueExpression(const std::string& variable):
    variable_(variable) {}

void GetValueExpression::accept(Visitor *visitor) {}