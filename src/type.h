#pragma once

#include <string>

struct SimpleType {
    std::string type;
    bool isArray;

    SimpleType() {}
    SimpleType(const std::string& type): type(type), isArray(false) {}
    SimpleType(SimpleType&&) = default;
    SimpleType(const SimpleType&) = default;
    SimpleType& operator=(const SimpleType&) = default;
};

enum class Type {
    eInt,
    eBool,
    eObject
};
