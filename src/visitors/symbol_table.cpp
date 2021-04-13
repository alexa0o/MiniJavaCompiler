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
    const ClassSymbol* classSymbol = nullptr;
    if (statement->type.getType() == Type::eObject) {
        classSymbol = current_layer_->getClass(Symbol(statement->type.type));
    }
    current_layer_->declareVar(VarSymbol(statement->variable, statement->type.getType(), classSymbol));
}

void SymbolTableVisitor::visit(PrintlnStatement *statement) {

}

void SymbolTableVisitor::visit(MethodDeclaration *declaration) {
    current_layer_ = sm_.create(current_layer_, declaration->name);
    auto methodScope = current_layer_;
    declaration->statementList->accept(this);
    current_layer_ = current_layer_->getParent();

    // create method symbol
    std::vector<VarSymbol> args;
    if (declaration->formals)
        for (auto& formal : declaration->formals->formals) {
            const ClassSymbol* classSymbol = nullptr;
            if (declaration->type.getType() == Type::eObject)
                classSymbol = current_layer_->getClass(Symbol(declaration->type.type));
            args.emplace_back(formal.name, formal.type.getType(), classSymbol);
        }

    current_layer_->declareMethod(
            MethodSymbol(declaration->name, std::move(args), declaration->type.getType(), methodScope)
            );
}

void SymbolTableVisitor::visit(VariableDeclaration *declaration) {
    const ClassSymbol* classSymbol = nullptr;
    if (declaration->type.getType() == Type::eObject) {
        classSymbol = current_layer_->getClass(Symbol(declaration->type.type));
    }
    current_layer_->declareVar(VarSymbol(declaration->name, declaration->type.getType(), classSymbol));
}

void SymbolTableVisitor::visit(Program *program) {
    current_layer_ = sm_.createGlobal();

    program->classes->accept(this);
    program->main->accept(this);

}

void SymbolTableVisitor::visit(ClassDeclaration *decl) {
    current_layer_->declareClass(ClassSymbol(decl->name));
    current_layer_ = sm_.create(current_layer_, decl->name);
    decl->declarations->accept(this);
    current_layer_ = current_layer_->getParent();

    auto classSymbol = current_layer_->getClass(Symbol(decl->name));
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
