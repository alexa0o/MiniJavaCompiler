#include "class.h"

ClassSymbol::ClassSymbol(const std::string &name) : Symbol(name) {

}

bool ClassSymbol::addVar(VarSymbol var) {
    return vars_.try_emplace(var.getName(), var).second;
}

bool ClassSymbol::addMethod(MethodSymbol method) {
    return methods_.try_emplace(method.getName(), method).second;
}

VarSymbol ClassSymbol::getVar(const std::string &name) const {
    return vars_.at(name);
}

MethodSymbol ClassSymbol::getMethod(const std::string &name) const {
    return methods_.at(name);
}
