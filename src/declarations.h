#pragma once

#include <string>
#include <vector>

#include "type.h"
#include "base_element.h"
#include "statements/statement_list.h"

class Declaration: public BaseElement {};

class DeclarationList: public Declaration {
public:
    void addDeclaration(Declaration* declaration);
    size_t size() const;
    void accept(Visitor* visitor) override;

    std::vector<Declaration*> declarations_;
};

class VariableDeclaration: public Declaration {
public:
    VariableDeclaration(Type type, const std::string& variable);
    void accept(Visitor* visitor) override;

private:
    std::string variable_;
    Type type_;
};

class MethodDeclaration: public Declaration {
public:
    MethodDeclaration(Type type, const std::string& name, StatementList* statementList);
    void accept(Visitor* visitor) override;

    std::string name_;
    StatementList* statementList_;
    Type type_;
};

class ClassDeclaration: public Declaration {
public:
    ClassDeclaration(const std::string& name, DeclarationList* declarations);
    void accept(Visitor* visitor) override;


    std::string name_;
    DeclarationList* declarations_;
};

class MainClassDeclaration: public ClassDeclaration {
public:
    MainClassDeclaration(const std::string& name, StatementList* statementList);
};

