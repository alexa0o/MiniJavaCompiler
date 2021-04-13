#pragma once

#include <string>

class Symbol {
public:
    Symbol(const std::string& name);
    std::string getName() const;

    bool operator==(const Symbol& s) const;

private:
    std::string name_;
};

template<>
struct std::hash<Symbol> {
    std::size_t operator()(const Symbol& s) const {
        return hash<std::string>()(s.getName());
    }
};