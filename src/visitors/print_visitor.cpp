#include <cassert>
#include <headers.h>

#include "print_visitor.h"

PrintVisitor::PrintVisitor(const std::string &filename): stream_(filename), num_tabs_(0) {

}

PrintVisitor::~PrintVisitor() {
    stream_.close();
}

void PrintVisitor::visit(AccessExpression *expression) {
    assert(false && "Not implemented");
}

void PrintVisitor::visit(BinaryExpression *expression) {
    printTabs();
    stream_ << "Binary expression:\n";

    ++num_tabs_;
    printTabs();
    stream_ << "Operator: " << expression->op->toString() << '\n';
    expression->leftExpression->accept(this);
    expression->rightExpression->accept(this);
    --num_tabs_;
}

void PrintVisitor::visit(GetValueExpression *expression) {
    printTabs();
    stream_ << "GetValue expression: "
    << expression->variable << '\n';
}

void PrintVisitor::visit(LengthExpression *expression) {
    assert(false && "Not implemented");

}

void PrintVisitor::visit(LiteralExpression *expression) {
    printTabs();
    stream_ << "Literal expression: "
    << expression->value << '\n';
}

void PrintVisitor::visit(NewExpression *expression) {
    assert(false && "Not implemented");
}

void PrintVisitor::visit(NewArrayExpression *expression) {
    assert(false && "Not implemented");
}

void PrintVisitor::visit(NotExpression *expression) {
    printTabs();
    stream_ << "Not expression:\n";

    ++num_tabs_;
    expression->expression->accept(this);
    --num_tabs_;
}

void PrintVisitor::visit(ThisExpression *expression) {
    assert(false && "Not implemented");
}

void PrintVisitor::visit(InvocationExpression *expression) {
    assert(false && "Not implemented");
}

void PrintVisitor::visit(LValueExpression *expression) {
    printTabs();
    stream_ << "LValue expression: "
    << expression->identifier << '\n';
}

void PrintVisitor::visit(AssertStatement *statement) {
    printTabs();
    stream_ << "Assert statement:\n";

    ++num_tabs_;
    statement->expression->accept(this);
    --num_tabs_;
}

void PrintVisitor::visit(AssignStatement *statement) {
    printTabs();
    stream_ << "Assign statement:\n";

    ++num_tabs_;
    statement->variable->accept(this);
    statement->expression->accept(this);
    --num_tabs_;
}

void PrintVisitor::visit(IfThenElseStatement *statement) {
    printTabs();
    stream_ << "IfThenElse statement:\n";

    ++num_tabs_;
    statement->condition->accept(this);
    statement->thenStatement->accept(this);
    statement->elseStatement->accept(this);
    --num_tabs_;
}

void PrintVisitor::visit(IfThenStatement *statement) {
    printTabs();
    stream_ << "IfThen statement:\n";

    ++num_tabs_;
    statement->condition->accept(this);
    statement->statement->accept(this);
    --num_tabs_;
}

void PrintVisitor::visit(InvocationStatement *statement) {
    assert(false && "Not implemented");
}

void PrintVisitor::visit(ReturnStatement *statement) {
    assert(false && "Not implemented");
}

void PrintVisitor::visit(ScopeStatement *statement) {
    printTabs();
    stream_ << "Scope statement:\n";

    ++num_tabs_;
    statement->statementList->accept(this);
    --num_tabs_;
}

void PrintVisitor::visit(StatementList *statement) {
    printTabs();
    stream_ << "StatementList:\n";

    ++num_tabs_;
    for (auto st : statement->statements)
        st->accept(this);
    --num_tabs_;
}

void PrintVisitor::visit(WhileStatement *statement) {
    printTabs();
    stream_ << "While statement:\n";

    ++num_tabs_;
    statement->condition->accept(this);
    statement->statement->accept(this);
    --num_tabs_;
}

void PrintVisitor::visit(DeclarationStatement *statement) {
    printTabs();
    stream_ << "Declaration statement:\n";
    ++num_tabs_;
    statement->declaration->accept(this);
    --num_tabs_;
}

void PrintVisitor::visit(VariableDeclarationAndAssignStatement *statement) {
    printTabs();
    stream_ << "DeclarationAndAssign statement: ";

    ++num_tabs_;
    stream_ << statement->variable << '\n';
    statement->expression->accept(this);
    --num_tabs_;
}

void PrintVisitor::visit(PrintlnStatement *statement) {
    printTabs();
    stream_ << "Println statement:\n";

    ++num_tabs_;
    statement->expression->accept(this);
    --num_tabs_;
}

void PrintVisitor::visit(MethodDeclaration *decl) {
    printTabs();
    stream_ << "Method decl: ";

    ++num_tabs_;
    stream_ << decl->name << '\n';
    decl->statementList->accept(this);
    --num_tabs_;
}

void PrintVisitor::visit(Program *program) {
    printTabs();
    stream_ << "Program:\n";

    program->main->declarations->declarations.front()->accept(this);
}

void PrintVisitor::printTabs() {
    for(auto i = 0; i < num_tabs_; ++i)
        stream_ << '\t';
}

void PrintVisitor::visit(VariableDeclaration *decl) {
    printTabs();
    stream_ << "Variable decl: " << decl->variable << '\n';
}

void PrintVisitor::visit(ClassDeclaration *decl) {

}

void PrintVisitor::visit(DeclarationList *decl) {

}









