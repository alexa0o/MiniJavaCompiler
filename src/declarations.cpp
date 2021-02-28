//
// Created by haritonov_a on 28.02.2021.
//

#include "declarations.h"

VariableDeclaration::VariableDeclaration(Type type, const std::string &variable):
    variable_(variable), type_(std::move(type)) {}

void VariableDeclaration::accept(Visitor *visitor) {}

ClassDeclaration::ClassDeclaration(const std::string &name, DeclarationList *declarations):
    name_(name), declarations_(declarations) {}

void ClassDeclaration::accept(Visitor *visitor) {}

MethodDeclaration::MethodDeclaration(Type type, const std::string &name, StatementList *statementList):
    type_(std::move(type)), name_(name), statementList_(statementList) {}

void MethodDeclaration::accept(Visitor *visitor) {}

void DeclarationList::addDeclaration(Declaration *declaration) {
    declarations_.push_back(declaration);
}

void DeclarationList::accept(Visitor *visitor) {

}

size_t DeclarationList::size() const {
    return declarations_.size();
}

MainClassDeclaration::MainClassDeclaration(const std::string &name, StatementList *statementList):
        ClassDeclaration(name, new DeclarationList()) {
    declarations_->addDeclaration(new MethodDeclaration(Type(), "main", statementList));
}
