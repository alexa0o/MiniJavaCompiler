#pragma once

#include <string>
#include <vector>

enum class Type {
    eVoid,
    eInt,
    eBool,
    eObject
};

struct TypeName {
    std::string type;
    bool isArray;

    TypeName() {}
    TypeName(const std::string& type): type(type), isArray(false) {}
    TypeName(TypeName&&) = default;
    TypeName(const TypeName&) = default;
    TypeName& operator=(const TypeName&) = default;

    Type getType() const {
        if (type == "int")
            return Type::eInt;
        if (type == "bool")
            return Type::eBool;
        return Type::eObject;
    }
};

struct Formal {
    TypeName type;
    std::string name;
};

struct Formals {
    std::vector<Formal> formals;

    void addFormal(const Formal& formal) {
        formals.push_back(formal);
    }
};