#include "declarations.h"

VariableDeclaration::VariableDeclaration(TypeName type, const std::string &variable):
        name(variable), type(std::move(type)) {}

void VariableDeclaration::accept(Visitor *visitor) {
    visitor->visit(this);
}

ClassDeclaration::ClassDeclaration(const std::string &name, DeclarationList *declarations):
        name(name), declarations(declarations) {}

void ClassDeclaration::accept(Visitor *visitor) {
    visitor->visit(this);
}

MethodDeclaration::MethodDeclaration(TypeName type, const std::string &name, Formals* formals, StatementList *statementList):
        type(std::move(type)), name(name), formals(formals), statementList(statementList) {}

void MethodDeclaration::accept(Visitor *visitor) {
    visitor->visit(this);
}

void DeclarationList::addDeclaration(Declaration *declaration) {
    declarations.push_back(declaration);
}

void DeclarationList::accept(Visitor *visitor) {
    visitor->visit(this);
}

size_t DeclarationList::size() const {
    return declarations.size();
}

MainClassDeclaration::MainClassDeclaration(const std::string &name, StatementList *statementList):
        ClassDeclaration(name, new DeclarationList()) {
    declarations->addDeclaration(new MethodDeclaration(TypeName(), "main", new Formals(), statementList));
}
