#include <gtest/gtest.h>

#include "symbols/scope_manager.h"
#include "symbols/class.h"

TEST(symbol_test, scope_manager_test) {
    ScopeManager sm;
    Scope* global = sm.createGlobal();
    for (auto i = 0; i < 10; ++i) {
        Scope* child = sm.create("global", "child" + std::to_string(i));
        global->addChild(child);
    }

    Scope* child7 = sm.get("global#child7");
    ASSERT_EQ(child7->getParent(), global);
}

TEST(symbol_test, class_symbol_test) {
    ClassSymbol main("main");
    ASSERT_EQ(main.getName(), "main");

    ClassSymbol class1("class1");

    VarSymbol class1Var("value", Type::eObject, &class1);
    main.addVar(class1Var);
    ASSERT_EQ(&class1, main.getVar("value").getClass());

    VarSymbol nonClassVar("non_class_val", Type::eInt);
    ASSERT_EQ(nonClassVar.getClass(), nullptr);

    ScopeManager sm;
    Scope* global = sm.createGlobal();
    global->declare(class1Var);
    ASSERT_TRUE(global->has(class1Var));

    global->put(class1Var, nullptr);
    ASSERT_EQ(global->get(class1Var), nullptr);

    MethodSymbol method1("method1", {class1Var}, Type::eInt, global);
    ASSERT_EQ(Type::eInt, method1.getResType());

    main.addMethod(method1);
    ASSERT_EQ(method1.getResType(), main.getMethod("method1").getResType());
}