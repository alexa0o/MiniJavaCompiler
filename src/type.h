#pragma once

#include <string>

enum class Type {
    eInt,
    eBool,
    eObject
};


struct SimpleType {
    std::string type;
    bool isArray;

    SimpleType() {}
    SimpleType(const std::string& type): type(type), isArray(false) {}
    SimpleType(SimpleType&&) = default;
    SimpleType(const SimpleType&) = default;
    SimpleType& operator=(const SimpleType&) = default;

    Type getType() const {
        if (type == "int")
            return Type::eInt;
        if (type == "bool")
            return Type::eBool;
        return Type::eObject;
    }
};