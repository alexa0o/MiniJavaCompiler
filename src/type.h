#pragma once

#include <string>

struct Type {
    std::string type;
    bool isArray;

    Type() {}
    Type(const std::string& type): type(type), isArray(false) {}
    Type(Type&&) = default;
    Type(const Type&) = default;
    Type& operator=(const Type&) = default;
};