#pragma once

#include <unordered_map>
#include <memory>

#include "scope.h"

class ScopeManager {
public:
    Scope* create(const std::string& parentName, const std::string& name);
    Scope* create(Scope* parent, const std::string& name);
    Scope* createGlobal();
    Scope* get(const std::string& scopeName) const;
private:
    std::unordered_map<std::string, std::unique_ptr<Scope>> scopes_;
};