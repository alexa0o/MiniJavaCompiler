#include "symbol.h"

Symbol::Symbol(const std::string &name): name_(name) {

}

std::string Symbol::getName() const {
    return name_;
}

bool Symbol::operator==(const Symbol &s) const {
    return name_ == s.name_;
}
