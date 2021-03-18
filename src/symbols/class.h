#pragma once

#include <unordered_map>

#include "symbol.h"
#include "var.h"
#include "method.h"

class ClassSymbol : public Symbol {
public:
    ClassSymbol(const std::string& name);
    bool addVar(VarSymbol var);
    bool addMethod(MethodSymbol method);

    VarSymbol getVar(const std::string& name) const;
    MethodSymbol getMethod(const std::string& name) const;
private:
    std::unordered_map<std::string, VarSymbol> vars_;
    std::unordered_map<std::string, MethodSymbol> methods_;
};
