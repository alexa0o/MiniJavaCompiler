#include "var.h"

VarSymbol::VarSymbol(const std::string &name, Type type, ClassSymbol *classSymbol)
    : Symbol(name), type_(type), classSymbol_(classSymbol) {

}

ClassSymbol *VarSymbol::getClass() const {
    return classSymbol_;
}

Type VarSymbol::getType() const {
    return type_;
}