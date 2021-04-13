#include <gtest/gtest.h>

#include "declarations.h"
#include "expressions/literal.h"
#include "statements/println.h"
#include "statements/declaration.h"
#include "visitors/symbol_table.h"
#include "program.h"
#include "type.h"

class TestAST : public ::testing::Test {
protected:

    template <class T, class... Args>
    T* create(Args... args) {
        auto element = new T(args...);
        pointers.push_back(element);
        return element;
    }

    void SetUp() {
        /*
         * class Test {
         *     public static void main() {
         *         System.out.println(42);
         *     }
         * }
         *
         * class A {
         *     public int b;
         *     public void foo() {
         *         int b;
         *     }
         * }
         */
        auto mainStatements = create<StatementList>();

        auto exp42 = create<LiteralExpression>(42);
        auto printlnStatement = create<PrintlnStatement>(exp42);

        auto main = create<MainClassDeclaration>("Test", mainStatements);

        auto classADeclList = create<DeclarationList>();
        auto classA = create<ClassDeclaration>("A", classADeclList);
        auto varDecl = create<VariableDeclaration>(TypeName{"int"}, "b");
        classADeclList->addDeclaration(varDecl);

        auto methodStatements = create<StatementList>();
        auto localVarDecl = create<VariableDeclaration>(TypeName{"int"}, "b");
        auto localVarDeclSt = create<DeclarationStatement>(localVarDecl);
        methodStatements->addStatement(localVarDeclSt);

        auto method = create<MethodDeclaration>(TypeName{"void"}, "foo", nullptr, methodStatements);
        classADeclList->addDeclaration(method);

        auto declList = create<DeclarationList>();
        declList->addDeclaration(classA);

        program = new Program(main, declList);
    }

    void TearDown() {
        for (auto pointer : pointers)
            delete pointer;
        delete program;
    }

    Program* program;
    std::vector<BaseElement*> pointers;
};

TEST_F(TestAST, symbol_table_visitor) {
    SymbolTableVisitor visitor;
    visitor.visit(program);
    auto root = visitor.getRoot();
    Symbol a("A");
    Symbol b("b");
    auto A = root->getClass(a);
    ASSERT_EQ(A->getName(), "A");

    ASSERT_TRUE(root->has(a));
    ASSERT_TRUE(visitor.getScopeManager().get("global#A")->has(b));
    ASSERT_TRUE(visitor.getScopeManager().get("global#A#foo")->has(b));
    ASSERT_EQ(root->getChildrenCount(), 2);
    ASSERT_THROW(root->get(Symbol("c")), std::runtime_error);
    ASSERT_THROW(root->declare(a), std::runtime_error);
}