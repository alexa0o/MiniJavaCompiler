#include "method.h"
#include "var.h"
#include "scope.h"

MethodSymbol::MethodSymbol(const std::string& name,
        std::vector<VarSymbol> args,
        Type resType,
        Scope *scope):
    Symbol(name), args_(std::move(args)), resType_(resType), scope_(scope) {

}

Type MethodSymbol::getResType() const {
    return resType_;
}
