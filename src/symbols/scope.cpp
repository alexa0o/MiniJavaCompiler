#include "scope.h"
#include "var.h"
#include "method.h"
#include "class.h"

#include <utility>

Scope::Scope(Scope *parent, std::string name): parent_(parent), name_(std::move(name)) {
    parent->addChild(this);
}

Scope::Scope(Scope *parent): parent_(parent) {
    parent_->addChild(this);
}

Scope::Scope(const std::string& name): name_(name), parent_(nullptr) {

}

Scope::Scope(): parent_(nullptr) {

}

void Scope::declare(const Symbol& symbol) {
    if (has(symbol))
        throw std::runtime_error("variable has declared");
    values_.emplace(symbol, std::make_shared<Object>());
}

bool Scope::has(const Symbol& var) const {
    return values_.find(var) != values_.end();
}

void Scope::put(const Symbol& var, std::shared_ptr<Object> value) {
    Scope* current = this;
    while(!current->has(var) && current->parent_ != nullptr)
        current = current->parent_;

    if (current->has(var))
        current->values_.find(var)->second = std::move(value);
    else
        throw std::runtime_error("variable not declared");
}

std::shared_ptr<Object> Scope::get(const Symbol &var) const {
    const Scope* current = this;
    while(!current->has(var) && current->parent_ != nullptr)
        current = current->parent_;

    if (current->has(var))
        return current->values_.find(var)->second;
    else
        throw std::runtime_error("variable not declared");
}

void Scope::addChild(Scope* child) {
    children_.push_back(child);
}

Scope *Scope::getParent() const {
    return parent_;
}

std::string Scope::getName() const {
    return name_;
}

size_t Scope::getChildrenCount() const {
    return children_.size();
}

void Scope::declareVar(const VarSymbol &varSymbol) {
    declare(varSymbol);
    varOffsets_.emplace(varSymbol, varSymbols_.size());
    varSymbols_.push_back(varSymbol);
}

void Scope::declareMethod(const MethodSymbol &methodSymbol) {
    declare(methodSymbol);
    methodOffsets_.emplace(methodSymbol, methodSymbols_.size());
    methodSymbols_.push_back(methodSymbol);
}

void Scope::declareClass(const ClassSymbol &classSymbol) {
    declare(classSymbol);
    classOffsets_.emplace(classSymbol, classSymbols_.size());
    classSymbols_.push_back(classSymbol);
}


