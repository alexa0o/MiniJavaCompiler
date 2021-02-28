find_package(BISON)
find_package(FLEX)

file(MAKE_DIRECTORY ${CMAKE_SOURCE_DIR}/src/gen)
set(GENERATED_FILES ${CMAKE_SOURCE_DIR}/src/gen)

include_directories(${GENERATED_FILES})
include_directories(${CMAKE_SOURCE_DIR}/src)

set(
        HEADERS
        driver.h
        ${GENERATED_FILES}/parser.hh
)

file(
        GLOB
        STATEMENTS_SOURCE
        "${CMAKE_SOURCE_DIR}/src/statements/*.cpp"
)

file(
        GLOB
        EXPRESSIONS_SOURCE
        "${CMAKE_SOURCE_DIR}/src/expressions/*.cpp"
)

file(
        GLOB
        OPERATORS_SOURCE
        "${CMAKE_SOURCE_DIR}/src/operators/*.cpp"
)

BISON_TARGET(
        Parser
        parser.y
        ${GENERATED_FILES}/parser.cpp
        DEFINES_FILE ${GENERATED_FILES}/parser.hh
)

FLEX_TARGET(
        Scanner
        scanner.l
        ${GENERATED_FILES}/scanner.cpp
)

ADD_FLEX_BISON_DEPENDENCY(Scanner Parser)

add_library(Statements SHARED ${STATEMENTS_SOURCE})
add_library(Expressions SHARED ${EXPRESSIONS_SOURCE})
add_library(Operators SHARED ${OPERATORS_SOURCE})

add_library(GrammarAndDriver SHARED driver.cpp declarations.cpp program.cpp ${BISON_Parser_OUTPUTS} ${FLEX_Scanner_OUTPUTS})
target_link_libraries(GrammarAndDriver Statements Expressions Operators)