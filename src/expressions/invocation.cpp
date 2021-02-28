//
// Created by haritonov_a on 28.02.2021.
//

#include "invocation.h"

InvocationExpression::InvocationExpression(Expression *expression, const std::string &name):
    expression_(expression), name_(name) {}

void InvocationExpression::accept(Visitor *visitor) {

}
