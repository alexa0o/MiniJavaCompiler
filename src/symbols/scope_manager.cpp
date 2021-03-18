#include "scope_manager.h"

Scope* ScopeManager::create(const std::string& parentName, const std::string& name) {
    const auto newName = parentName + "#" + name;
    scopes_.emplace(newName, std::make_unique<Scope>(scopes_.at(parentName).get()));
    return scopes_.at(newName).get();
}

Scope *ScopeManager::get(const std::string &scopeName) const {
    return scopes_.at(scopeName).get();
}

Scope *ScopeManager::createGlobal() {
    scopes_.emplace("global", std::make_unique<Scope>());
    return scopes_.at("global").get();
}
