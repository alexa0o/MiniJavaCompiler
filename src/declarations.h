#pragma once

#include <string>
#include <vector>

#include "type.h"
#include "base_element.h"
#include "statements/statement_list.h"

class Declaration: public BaseElement {};

class DeclarationList : public BaseElement {
public:
    void addDeclaration(Declaration* declaration);
    size_t size() const;
    void accept(Visitor* visitor) override;

    std::vector<Declaration*> declarations;
};

class VariableDeclaration: public Declaration {
public:
    VariableDeclaration(TypeName type, const std::string& variable);
    void accept(Visitor* visitor) override;

    std::string name;
    TypeName type;
};

class MethodDeclaration: public Declaration {
public:
    MethodDeclaration(TypeName type, const std::string& name, Formals* formals, StatementList* statementList);
    void accept(Visitor* visitor) override;

    std::string name;
    Formals* formals;
    StatementList* statementList;
    TypeName type;
};

class ClassDeclaration: public Declaration {
public:
    ClassDeclaration(const std::string& name, DeclarationList* declarations);
    void accept(Visitor* visitor) override;

    std::string name;
    DeclarationList* declarations;
};

class MainClassDeclaration: public ClassDeclaration {
public:
    MainClassDeclaration(const std::string& name, StatementList* statementList);
};

