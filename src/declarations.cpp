#include "declarations.h"

VariableDeclaration::VariableDeclaration(SimpleType type, const std::string &variable):
        variable(variable), type(std::move(type)) {}

void VariableDeclaration::accept(Visitor *visitor) {
    visitor->visit(this);
}

ClassDeclaration::ClassDeclaration(const std::string &name, DeclarationList *declarations):
        name(name), declarations(declarations) {}

void ClassDeclaration::accept(Visitor *visitor) {
    visitor->visit(this);
}

MethodDeclaration::MethodDeclaration(SimpleType type, const std::string &name, StatementList *statementList):
        type(std::move(type)), name(name), statementList(statementList) {}

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
    declarations->addDeclaration(new MethodDeclaration(SimpleType(), "main", statementList));
}
