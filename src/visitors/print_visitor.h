#pragma once

#include <fstream>

#include "visitor.h"

class PrintVisitor: public Visitor {
public:
    PrintVisitor(const std::string& filename);
    ~PrintVisitor();

#define OVERRIDE_VISIT(BASE_ELEMENT_TYPE) void visit(BASE_ELEMENT_TYPE* expression) override

    OVERRIDE_VISIT(AccessExpression);
    OVERRIDE_VISIT(BinaryExpression);
    OVERRIDE_VISIT(GetValueExpression);
    OVERRIDE_VISIT(LengthExpression);
    OVERRIDE_VISIT(LiteralExpression);
    OVERRIDE_VISIT(NewExpression);
    OVERRIDE_VISIT(NewArrayExpression);
    OVERRIDE_VISIT(NotExpression);
    OVERRIDE_VISIT(ThisExpression);
    OVERRIDE_VISIT(InvocationExpression);
    OVERRIDE_VISIT(LValueExpression);

#undef OVERRIDE_VISIT

#define OVERRIDE_VISIT(BASE_ELEMENT_TYPE) void visit(BASE_ELEMENT_TYPE* statement) override

    OVERRIDE_VISIT(AssertStatement);
    OVERRIDE_VISIT(AssignStatement);
    OVERRIDE_VISIT(IfThenElseStatement);
    OVERRIDE_VISIT(IfThenStatement);
    OVERRIDE_VISIT(InvocationStatement);
    OVERRIDE_VISIT(ReturnStatement);
    OVERRIDE_VISIT(ScopeStatement);
    OVERRIDE_VISIT(StatementList);
    OVERRIDE_VISIT(WhileStatement);
    OVERRIDE_VISIT(DeclarationStatement);
    OVERRIDE_VISIT(VariableDeclarationAndAssignStatement);
    OVERRIDE_VISIT(PrintlnStatement);

#undef OVERRIDE_VISIT

#define OVERRIDE_VISIT(BASE_ELEMENT_TYPE) void visit(BASE_ELEMENT_TYPE* decl) override

    OVERRIDE_VISIT(MethodDeclaration);
    OVERRIDE_VISIT(VariableDeclaration);
    OVERRIDE_VISIT(ClassDeclaration);
    OVERRIDE_VISIT(DeclarationList);

#undef OVERRIDE_VISIT

    void visit(Program* program) override;

private:
    void printTabs();
    std::ofstream stream_;
    int num_tabs_;
};