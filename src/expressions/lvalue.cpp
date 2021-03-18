#include "lvalue.h"

LValueExpression::LValueExpression(const std::string &identifier, Expression* index):
    identifier(identifier), index(index) {

}

void LValueExpression::accept(Visitor *visitor) {
    visitor->visit(this);
}
