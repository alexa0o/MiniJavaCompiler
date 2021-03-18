#pragma once

#include <vector>
#include <memory>
#include <unordered_map>

#include "var.h"
#include "objects/object.h"

class Scope {
public:
    Scope(Scope* parent);
    Scope();

    void declareVariable(const VarSymbol& var);
    bool has(const VarSymbol& var) const;
    void put(const VarSymbol& var, std::shared_ptr<Object> value);
    std::shared_ptr<Object> get(const VarSymbol& var) const;

    void addChild(Scope* child);
    Scope* getParent() const;

private:
    std::unordered_map<Symbol, std::shared_ptr<Object>> values_;
    std::vector<VarSymbol> varSymbols_;
    std::vector<Scope*> children_;
    Scope* parent_;
};