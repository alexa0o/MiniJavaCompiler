#include <gtest/gtest.h>

#include "driver.h"

size_t countStatementsInMethod(Declaration* decl) {
    auto mdecl = dynamic_cast<MethodDeclaration*>(decl);
    return mdecl->statementList_->statements_.size();
}

ClassDeclaration* toClass(Declaration* decl) {
    return dynamic_cast<ClassDeclaration*>(decl);
}

TEST(ast_test, simple_sample) {
    Driver driver;
    driver.parse("sample.java");
    auto program = driver.program;

    // main class + 1
    ASSERT_EQ(program->classes_->size(), 1);

    // main method with 1 statement
    ASSERT_EQ(countStatementsInMethod(program->main_->declarations_->declarations_.front()), 1);

    // factorial method with 4 statement, because if-then-else is 1 statement with inside statements
    ASSERT_EQ( countStatementsInMethod(toClass(program->classes_->declarations_.front())->declarations_->declarations_.front()), 4 );
}