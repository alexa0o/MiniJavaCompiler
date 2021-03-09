#pragma once

#include <unordered_map>

#include "visitor.h"

class Interpreter: public Visitor {
public:
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

#undef OVERRIDE_VISIT

    void visit(Program* program) override;

    int getResult(Program* program);

private:
    std::unordered_map<std::string, int> variables_;

    bool is_tos_expression_;
    int tos_value_;
    int* lvalue_;

    void setTosValue(int value);
    void unsetTosValue();

    void setLValue(int& value);
    void unsetLValue();
};