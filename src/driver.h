#pragma once

#include <unordered_map>
#include <string>
#include <fstream>

#include "scanner.h"
#include "parser.hh"
#include "program.h"

class Driver {
public:
    Driver();
    int result;
    int parse(const std::string& f);
    int Evaluate();
    std::string file;
    bool trace_parsing;

    void scan_begin();
    void scan_end();

    bool trace_scanning;
    yy::location location;

    friend class Scanner;
    Scanner scanner;
    yy::parser parser;

    Program* program;

private:
    std::ifstream stream;
};
