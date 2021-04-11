#include <declarations.h>
#include <headers.h>
#include "symbol_table.h"
#include "symbols/var.h"

void SymbolTableVisitor::visit(AccessExpression *expression) {

}

void SymbolTableVisitor::visit(BinaryExpression *expression) {

}

void SymbolTableVisitor::visit(GetValueExpression *expression) {

}

void SymbolTableVisitor::visit(LengthExpression *expression) {

}

void SymbolTableVisitor::visit(LiteralExpression *expression) {

}

void SymbolTableVisitor::visit(NewExpression *expression) {

}

void SymbolTableVisitor::visit(NewArrayExpression *expression) {

}

void SymbolTableVisitor::visit(NotExpression *expression) {

}

void SymbolTableVisitor::visit(ThisExpression *expression) {

}

void SymbolTableVisitor::visit(InvocationExpression *expression) {

}

void SymbolTableVisitor::visit(LValueExpression *expression) {

}

void SymbolTableVisitor::visit(AssertStatement *statement) {

}

void SymbolTableVisitor::visit(AssignStatement *statement) {

}

void SymbolTableVisitor::visit(IfThenElseStatement *statement) {
    auto number = std::to_string(current_layer_->getChildrenCount());
    current_layer_ = sm_.create(current_layer_, std::string("then") + number);
    statement->thenStatement->accept(this);
    current_layer_ = current_layer_->getParent();
    current_layer_ = sm_.create(current_layer_, std::string("else") + number);
    statement->elseStatement->accept(this);
    current_layer_ = current_layer_->getParent();
}

void SymbolTableVisitor::visit(IfThenStatement *statement) {
    current_layer_ = sm_.create(current_layer_, std::string("then") + std::to_string(current_layer_->getChildrenCount()));
    statement->statement->accept(this);
    current_layer_ = current_layer_->getParent();
}

void SymbolTableVisitor::visit(InvocationStatement *statement) {

}

void SymbolTableVisitor::visit(ReturnStatement *statement) {

}

void SymbolTableVisitor::visit(ScopeStatement *statement) {
    current_layer_ = sm_.create(current_layer_, std::to_string(current_layer_->getChildrenCount()));
    current_layer_ = current_layer_->getParent();
}

void SymbolTableVisitor::visit(StatementList *statement) {
    for (auto st : statement->statements)
        st->accept(this);
}

void SymbolTableVisitor::visit(WhileStatement *statement) {
    current_layer_ = sm_.create(current_layer_, std::string("while") + std::to_string(current_layer_->getChildrenCount()));
    current_layer_ = current_layer_->getParent();
}

void SymbolTableVisitor::visit(DeclarationStatement *statement) {
    statement->declaration->accept(this);
}

void SymbolTableVisitor::visit(VariableDeclarationAndAssignStatement *statement) {
    current_layer_->declareVar(VarSymbol(statement->variable, statement->type.getType()));
}

void SymbolTableVisitor::visit(PrintlnStatement *statement) {

}

void SymbolTableVisitor::visit(MethodDeclaration *declaration) {
    current_layer_->declare(Symbol(declaration->name)); // TODO:
    current_layer_ = sm_.create(current_layer_, declaration->name);
    declaration->statementList->accept(this);
    current_layer_ = current_layer_->getParent();
}

void SymbolTableVisitor::visit(VariableDeclaration *declaration) {
    current_layer_->declareVar(VarSymbol(declaration->variable, declaration->type.getType()));
}

void SymbolTableVisitor::visit(Program *program) {
    current_layer_ = sm_.createGlobal();

    program->classes->accept(this);
    program->main->accept(this);

}

void SymbolTableVisitor::visit(ClassDeclaration *decl) {
    current_layer_->declare(Symbol(decl->name)); // TODO:
    current_layer_ = sm_.create(current_layer_, decl->name);
    decl->declarations->accept(this);
    current_layer_ = current_layer_->getParent();
}

void SymbolTableVisitor::visit(DeclarationList *decl) {
    for (auto d : decl->declarations)
        d->accept(this);
}

Scope *SymbolTableVisitor::getRoot() const {
    return current_layer_;
}

const ScopeManager &SymbolTableVisitor::getScopeManager() const {
    return sm_;
}
