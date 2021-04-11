#pragma once

#include <vector>

#include "symbol.h"
#include "type.h"

class Scope;
class VarSymbol;

class MethodSymbol : public Symbol {
public:
    MethodSymbol(const std::string& name, std::vector<VarSymbol> args, Type resType, Scope* scope);

    Type getResType() const;
private:
    std::vector<VarSymbol> args_;
    Type resType_;
    Scope* scope_;
};
