#pragma once

#include "symbol.h"
#include "type.h"

class ClassSymbol;

class VarSymbol : public Symbol {
public:
    VarSymbol(const std::string &name, Type type, const ClassSymbol *classSymbol = nullptr);

    const ClassSymbol* getClass() const;
    Type getType() const;

private:
    Type type_;
    const ClassSymbol* classSymbol_;
};
