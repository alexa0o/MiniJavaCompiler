#pragma once

#include "visitor.h"
#include "symbols/scope.h"
#include "symbols/scope_manager.h"

class SymbolTableVisitor : public Visitor {
public:
    void visit(AccessExpression *expression) override;
    void visit(BinaryExpression *expression) override;
    void visit(GetValueExpression *expression) override;
    void visit(LengthExpression *expression) override;
    void visit(LiteralExpression *expression) override;
    void visit(NewExpression *expression) override;
    void visit(NewArrayExpression *expression) override;
    void visit(NotExpression *expression) override;
    void visit(ThisExpression *expression) override;
    void visit(InvocationExpression *expression) override;
    void visit(LValueExpression *expression) override;
    void visit(AssertStatement *statement) override;
    void visit(AssignStatement *statement) override;
    void visit(IfThenElseStatement *statement) override;
    void visit(IfThenStatement *statement) override;
    void visit(InvocationStatement *statement) override;
    void visit(ReturnStatement *statement) override;
    void visit(ScopeStatement *statement) override;
    void visit(StatementList *statement) override;
    void visit(WhileStatement *statement) override;
    void visit(DeclarationStatement *statement) override;
    void visit(VariableDeclarationAndAssignStatement *statement) override;
    void visit(PrintlnStatement *statement) override;
    void visit(MethodDeclaration *declaration) override;
    void visit(VariableDeclaration *declaration) override;
    void visit(Program *program) override;
    void visit(ClassDeclaration* decl) override;
    void visit(DeclarationList* decl) override;

    Scope* getRoot() const;
    const ScopeManager& getScopeManager() const;
private:
    ScopeManager sm_;
    Scope* current_layer_;
};
