#pragma once

#include "forward_decl.h"

class Visitor {
public:

#define VIRTUAL_VISIT(BASE_ELEMENT_TYPE) virtual void visit(BASE_ELEMENT_TYPE* expression) = 0

VIRTUAL_VISIT(AccessExpression);
VIRTUAL_VISIT(BinaryExpression);
VIRTUAL_VISIT(GetValueExpression);
VIRTUAL_VISIT(LengthExpression);
VIRTUAL_VISIT(LiteralExpression);
VIRTUAL_VISIT(NewExpression);
VIRTUAL_VISIT(NewArrayExpression);
VIRTUAL_VISIT(NotExpression);
VIRTUAL_VISIT(ThisExpression);
VIRTUAL_VISIT(InvocationExpression);
VIRTUAL_VISIT(LValueExpression);

#undef VIRTUAL_VISIT

#define VIRTUAL_VISIT(BASE_ELEMENT_TYPE) virtual void visit(BASE_ELEMENT_TYPE* statement) = 0

VIRTUAL_VISIT(AssertStatement);
VIRTUAL_VISIT(AssignStatement);
VIRTUAL_VISIT(IfThenElseStatement);
VIRTUAL_VISIT(IfThenStatement);
VIRTUAL_VISIT(InvocationStatement);
VIRTUAL_VISIT(ReturnStatement);
VIRTUAL_VISIT(ScopeStatement);
VIRTUAL_VISIT(StatementList);
VIRTUAL_VISIT(WhileStatement);
VIRTUAL_VISIT(DeclarationStatement);
VIRTUAL_VISIT(VariableDeclarationAndAssignStatement);
VIRTUAL_VISIT(PrintlnStatement);

#undef VIRTUAL_VISIT

#define VIRTUAL_VISIT(BASE_ELEMENT_TYPE) virtual void visit(BASE_ELEMENT_TYPE* declaration) = 0

VIRTUAL_VISIT(MethodDeclaration);
VIRTUAL_VISIT(VariableDeclaration);

#undef VIRTUAL_VISIT

    virtual void visit(Program* program) = 0;
};