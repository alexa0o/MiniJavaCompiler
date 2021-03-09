#include "get_value.h"

GetValueExpression::GetValueExpression(const std::string& variable):
        variable(variable) {}

void GetValueExpression::accept(Visitor *visitor) {
    visitor->visit(this);
}