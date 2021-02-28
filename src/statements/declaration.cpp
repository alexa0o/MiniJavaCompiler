#include "declaration.h"

DeclarationStatement::DeclarationStatement(Declaration *declaration):
    declaration_(declaration) {}

void DeclarationStatement::accept(Visitor *visitor) {}

VariableDeclarationAndAssignStatement::VariableDeclarationAndAssignStatement(const std::string &variable,
                                                                             Expression *expression):
    variable_(variable), expression_(expression) {}

void VariableDeclarationAndAssignStatement::accept(Visitor *visitor) {}
