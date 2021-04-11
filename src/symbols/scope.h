#pragma once

#include <vector>
#include <memory>
#include <string>
#include <unordered_map>

#include "symbol.h"
#include "objects/object.h"

#include "var.h"
#include "method.h"
#include "class.h"

class Scope {
public:
    Scope(Scope* parent, std::string name);
    Scope(Scope* parent);
    Scope(const std::string& name);
    Scope();

    void declare(const Symbol& symbol);
    void declareVar(const VarSymbol& varSymbol);
    void declareMethod(const MethodSymbol& methodSymbol);
    void declareClass(const ClassSymbol& classSymbol);
    bool has(const Symbol& var) const;
    void put(const Symbol& var, std::shared_ptr<Object> value);
    std::shared_ptr<Object> get(const Symbol& var) const;

    void addChild(Scope* child);
    Scope* getParent() const;
    std::string getName() const;
    size_t getChildrenCount() const;

private:
    std::unordered_map<Symbol, std::shared_ptr<Object>> values_;
    std::vector<VarSymbol> varSymbols_;
    std::vector<MethodSymbol> methodSymbols_;
    std::vector<ClassSymbol> classSymbols_;
    std::unordered_map<Symbol, size_t> varOffsets_;
    std::unordered_map<Symbol, size_t> methodOffsets_;
    std::unordered_map<Symbol, size_t> classOffsets_;

    std::vector<Scope*> children_;
    Scope* parent_;

    std::string name_;
};