#include "declaration.h"

DeclarationStatement::DeclarationStatement(Declaration *declaration):
    declaration_(declaration) {}

void DeclarationStatement::accept(Visitor *visitor) {}

VariableDeclarationAndAssignStatement::VariableDeclarationAndAssignStatement(Type type,
                                                                             const std::string &variable,
                                                                             Expression *expression):
    variable_(variable), expression_(expression), type_(std::move(type)) {}

void VariableDeclarationAndAssignStatement::accept(Visitor *visitor) {}
