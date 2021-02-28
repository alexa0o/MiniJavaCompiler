#pragma once

#include "declarations.h"

class Program {
public:
    Program(MainClassDeclaration* main, DeclarationList* classes);

    MainClassDeclaration* main_;
    DeclarationList* classes_;
};

