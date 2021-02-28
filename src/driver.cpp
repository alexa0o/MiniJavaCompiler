#include <iostream>

#include "driver.h"

Driver::Driver():
    trace_parsing(false),
    trace_scanning(false),
    scanner(*this), parser(scanner, *this) {}

int Driver::parse(const std::string& f) {
    file = f;
    location.initialize(&file);
    scan_begin();
    parser.set_debug_level(trace_parsing);
    int res = parser();
    std::cout << "parser " << res << '\n';
    scan_end();
    return res;
}

int Driver::Evaluate() {
    return 0;
}

void Driver::scan_begin() {
    scanner.set_debug(trace_scanning);
    if (!file.empty()) {
        stream.open(file);
        std::cout << file << '\n';
        scanner.yyrestart(&stream);
    }
}

void Driver::scan_end() {
    stream.close();
}
