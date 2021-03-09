#include "declaration.h"

DeclarationStatement::DeclarationStatement(Declaration *declaration):
        declaration(declaration) {}

void DeclarationStatement::accept(Visitor *visitor) {
    visitor->visit(this);
}

VariableDeclarationAndAssignStatement::VariableDeclarationAndAssignStatement(Type type,
                                                                             const std::string &variable,
                                                                             Expression *expression):
        variable(variable), expression(expression), type(std::move(type)) {}

void VariableDeclarationAndAssignStatement::accept(Visitor *visitor) {
    visitor->visit(this);
}
