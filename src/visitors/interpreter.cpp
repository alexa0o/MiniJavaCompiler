#include <cassert>
#include <iostream>

#include "interpreter.h"
#include "headers.h"

void Interpreter::setTosValue(int value) {
    tos_value_ = value;
    is_tos_expression_ = true;
}

void Interpreter::unsetTosValue() {
    tos_value_ = 0;
    is_tos_expression_ = false;
}

void Interpreter::visit(BinaryExpression *expression) {
    expression->leftExpression->accept(this);
    auto value = tos_value_;

    expression->rightExpression->accept(this);
    value = (*expression->op)(value, tos_value_);

    setTosValue(value);
}

void Interpreter::visit(GetValueExpression *expression) {
    const auto& variable = expression->variable;

    if (variables_.find(variable) == variables_.end())
        setTosValue(0);
    else
        setTosValue(variables_.at(variable));
}

void Interpreter::visit(LiteralExpression *expression) {
    setTosValue(expression->value);
}

void Interpreter::visit(NotExpression *expression) {
    expression->expression->accept(this);
    setTosValue(!tos_value_);
}

// NOT IMPLEMENTED EXPRESSIONS BLOCK

void Interpreter::visit(AccessExpression *expression) {
    assert(false && "Not implemented");
}

void Interpreter::visit(LengthExpression *expression) {
    assert(false && "Not implemented");
}

void Interpreter::visit(NewExpression *expression) {
    assert(false && "Not implemented");
}

void Interpreter::visit(NewArrayExpression *expression) {
    assert(false && "Not implemented");
}

void Interpreter::visit(ThisExpression *expression) {
    assert(false && "Not implemented");
}

void Interpreter::visit(InvocationExpression *expression) {
    assert(false && "Not implemented");
}

// END OF BLOCK

void Interpreter::visit(AssertStatement *statement) {
    statement->expression->accept(this);
    assert(tos_value_);
    unsetTosValue();
}

void Interpreter::visit(AssignStatement *statement) {
    statement->variable->accept(this);
    statement->expression->accept(this);
    *lvalue_ = tos_value_;

    unsetTosValue();
    unsetLValue();
}

void Interpreter::visit(IfThenElseStatement *statement) {
    statement->condition->accept(this);
    if (tos_value_)
        statement->thenStatement->accept(this);
    else
        statement->elseStatement->accept(this);
    unsetTosValue();
}

void Interpreter::visit(IfThenStatement *statement) {
    statement->condition->accept(this);
    if (tos_value_)
        statement->statement->accept(this);
    unsetTosValue();
}

void Interpreter::visit(ScopeStatement *statement) {
    statement->statementList->accept(this);
    unsetTosValue();
}

void Interpreter::visit(WhileStatement *statement) {
    statement->condition->accept(this);
    while (tos_value_) {
        statement->statement->accept(this);
        statement->condition->accept(this);
    }
    unsetTosValue(); // ???
}

void Interpreter::visit(DeclarationStatement *statement) {
    statement->declaration->accept(this);
}

void Interpreter::visit(VariableDeclarationAndAssignStatement *statement) {
    statement->expression->accept(this);
    variables_.emplace(statement->variable, tos_value_);
    unsetTosValue();
}

void Interpreter::visit(PrintlnStatement *statement) {
    statement->expression->accept(this);
    std::cout << tos_value_ << '\n';
    unsetTosValue();
}

void Interpreter::visit(StatementList *statement) {
    for (auto st : statement->statements)
        st->accept(this);
}

void Interpreter::visit(InvocationStatement *statement) {
    assert(false && "Not implemented");
}

void Interpreter::visit(ReturnStatement *statement) {
    assert(false && "Not implemented");
}

int Interpreter::getResult(Program *program) {
    unsetTosValue();
    visit(program);
    return tos_value_;
}

void Interpreter::visit(Program *program) {
    program->main->declarations->declarations.front()->accept(this);
}

void Interpreter::visit(MethodDeclaration *decl) {
    decl->statementList->accept(this); // ???
}

void Interpreter::visit(LValueExpression *expression) {
    setLValue(variables_[expression->identifier]);
}

void Interpreter::setLValue(int &value) {
    lvalue_ = &value;
}

void Interpreter::unsetLValue() {
    lvalue_ = nullptr;
}

void Interpreter::visit(VariableDeclaration *decl) {
    variables_[decl->name] = 0;
}

void Interpreter::visit(ClassDeclaration *decl) {

}

void Interpreter::visit(DeclarationList *decl) {

}



