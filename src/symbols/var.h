#pragma once

#include "symbol.h"
#include "type.h"

class ClassSymbol;

class VarSymbol : public Symbol {
public:
    VarSymbol(const std::string &name, Type type, ClassSymbol *classSymbol = nullptr);

    ClassSymbol* getClass() const;
private:
    Type type_;
    ClassSymbol* classSymbol_;
};
