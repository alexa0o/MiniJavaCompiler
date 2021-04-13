#include "var.h"

VarSymbol::VarSymbol(const std::string &name, Type type, const ClassSymbol *classSymbol)
    : Symbol(name), type_(type), classSymbol_(classSymbol) {

}

const ClassSymbol *VarSymbol::getClass() const {
    return classSymbol_;
}

Type VarSymbol::getType() const {
    return type_;
}