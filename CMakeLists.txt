cmake_minimum_required(VERSION 3.10)
project(MiniJavaCompiler)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(${MiniJavaCompiler_SOURCE_DIR}/src)

include_directories(src)
include_directories(src/gen)

add_executable(MiniJavaCompiler main.cpp)
target_link_libraries(MiniJavaCompiler GrammarAndDriver)

enable_testing()
find_package(GTest REQUIRED)
add_executable( runUnitTests ${CMAKE_SOURCE_DIR}/tests/ast_test.cpp ${CMAKE_SOURCE_DIR}/tests/symbol_test.cpp)
target_link_libraries(runUnitTests gtest gtest_main GrammarAndDriver Symbols Objects pthread)
add_test( runUnitTests runUnitTests )
configure_file(tests/sample.java ${CMAKE_BINARY_DIR}/sample.java COPYONLY)