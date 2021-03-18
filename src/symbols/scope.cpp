#include "scope.h"

#include <utility>

Scope::Scope(Scope *parent): parent_(parent) {
    parent_->addChild(this);
}

Scope::Scope(): parent_(nullptr) {

}

void Scope::declareVariable(const VarSymbol& var) {
    if (has(var))
        throw std::runtime_error("variable has declared");
    values_.emplace(var, std::make_shared<Object>());
    varSymbols_.push_back(var);
}

bool Scope::has(const VarSymbol& var) const {
    return values_.find(var) != values_.end();
}

void Scope::put(const VarSymbol& var, std::shared_ptr<Object> value) {
    Scope* current = this;
    while(!current->has(var) && current->parent_ != nullptr)
        current = current->parent_;

    if (current->has(var))
        current->values_.find(var)->second = std::move(value);
    else
        throw std::runtime_error("variable not declared");
}

std::shared_ptr<Object> Scope::get(const VarSymbol &var) const {
    const Scope* current = this;
    while(!current->has(var) && current->parent_ != nullptr)
        current = current->parent_;

    if (current->has(var))
        return current->values_.find(var)->second;
    else
        throw std::runtime_error("variable not declared");
}

void Scope::addChild(Scope *child) {
    children_.push_back(child);
}

Scope *Scope::getParent() const {
    return parent_;
}

