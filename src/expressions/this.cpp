#include "this.h"

ThisExpression::ThisExpression() {}

void ThisExpression::accept(Visitor *visitor) {
    visitor->visit(this);
}