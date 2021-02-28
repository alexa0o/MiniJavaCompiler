%skeleton "lalr1.cc"
%require "3.5"

%defines
%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
  #include <string>
  class Scanner;
  class Driver;

  class Expression;
  class AccessExpression;
  class BinaryExpression;
  class GetValueExpression;
  class LengthExpression;
  class LiteralExpression;
  class NewExpression;
  class NewArrayExpression;
  class NotExpression;
  class ThisExpression;

  class Statement;
  class AssertStatement;
  class AssignStatement;
  class IfThenStatement;
  class IfThenElseStatement;
  class InvocationStatement;
  class ReturnStatement;
  class ScopeStatement;
  class StatementList;
  class WhileStatement;
  class DeclarationStatement;
  class VariableDeclarationAndAssignStatement;
  class PrintlnStatement;

  struct Operator;
  struct DAmpersandOperator;
  struct DAssignOperator;
  struct DPipeOperator;
  struct LSTOperator;
  struct RSTOperator;
  struct MinusOperator;
  struct PercentOperator;
  struct PlusOperator;
  struct SlashOperator;
  struct StarOperator;

  class Declaration;
  class ClassDeclaration;
  class MainClassDeclaration;
  class VariableDeclaration;
  class MethodDeclaration;
  class DeclarationList;

  class Program;
}

%define parse.trace
%define parse.error verbose

%code {
  #include "driver.h"
  #include "location.hh"

  #include "expressions/access.h"
  #include "expressions/binary.h"
  #include "expressions/get_value.h"
  #include "expressions/length.h"
  #include "expressions/literal.h"
  #include "expressions/new.h"
  #include "expressions/new_array.h"
  #include "expressions/not.h"
  #include "expressions/this.h"

  #include "statements/assert.h"
  #include "statements/assign.h"
  #include "statements/if_then.h"
  #include "statements/if_then_else.h"
  #include "statements/invocation.h"
  #include "statements/return.h"
  #include "statements/scope.h"
  #include "statements/statement_list.h"
  #include "statements/while.h"
  #include "statements/declaration.h"
  #include "statements/println.h"

  #include "operators/dampersand.h"
  #include "operators/dassign.h"
  #include "operators/dpipe.h"
  #include "operators/lts.h"
  #include "operators/rts.h"
  #include "operators/minus.h"
  #include "operators/percent.h"
  #include "operators/plus.h"
  #include "operators/slash.h"
  #include "operators/star.h"

  #include "declarations.h"
  #include "program.h"

  static yy::parser::symbol_type yylex(Scanner &scanner, Driver& driver) {
    return scanner.ScanToken();
  }
}

%lex-param { Scanner &scanner }
%lex-param { Driver &driver }
%parse-param { Scanner &scanner }
%parse-param { Driver &driver }

%locations

%define api.token.prefix {TOK_}

%token
    END 0 "end of file"

    MINUS "-"
    PLUS "+"
    STAR "*"
    SLASH "/"
    PERCENT "%"
    DAMPERSAND "&&"
    DPIPE "||"
    DASSIGN "=="
    LTS "<"
    RTS ">"

    EMARK "!"

    ASSIGN "="
    LPAREN "("
    RPAREN ")"
    LSB "["
    RSB "]"
    LBRACE "{"
    RBRACE "}"

    DOT "."
    COMMA ","
    SEMICOLON ";"

    INT "int"
    VOID "void"
    BOOLEAN "boolean"

    IF
    ELSE

    RETURN

    WHILE

    ASSERT
    PRINTLN

    CLASS
    PUBLIC
    THIS
    LENGTH
    EXTENDS
    STATIC
    MAIN
    NEW

    TRUE
    FALSE
;

%token <std::string> IDENTIFIER "identifier"
%token <int> NUMBER "number"

%nterm <Expression*> expr
%nterm <Statement*> statement
%nterm <StatementList*> statements
%nterm <Operator*> binary_operator
%nterm <DeclarationList*> declarations
%nterm <DeclarationList*> class_declarations
%nterm <Declaration*> class_declaration
%nterm <Declaration*> declaration
%nterm <Declaration*> variable_declaration local_variable_declaration
%nterm <Declaration*> method_declaration
%nterm <MainClassDeclaration*> main_class
%nterm <Program*> program


%%
%start program;

program:
    main_class class_declarations { $$ = new Program($1, $2); driver.program = $$; }

main_class:
    CLASS "identifier" "{" PUBLIC STATIC VOID MAIN "(" ")" "{"
        statements "}" "}" { $$ = new MainClassDeclaration($2, $11); }

class_declarations:
    %empty { $$ = new DeclarationList(); }
    | class_declarations class_declaration { $1->addDeclaration($2); $$ = $1; }

class_declaration:
    CLASS "identifier" extend "{" declarations "}" { $$ = new ClassDeclaration($2, $5); }

extend:
    %empty
    | EXTENDS "identifier"

declarations:
    %empty { $$ = new DeclarationList(); }
    | declarations declaration { $1->addDeclaration($2); $$ = $1; }

declaration:
    method_declaration { $$ = $1; }
    | variable_declaration { $$ = $1; }

method_declaration:
    PUBLIC type "identifier" "(" formals ")" "{" statements "}" { $$ = new MethodDeclaration($3, $8); }

formals:
    %empty
    | variable
    | formals "," variable

variable:
    type "identifier"

variable_declaration:
    type "identifier" ";" { $$ = new VariableDeclaration($2); }

type:
    simple_type
    | array_type

simple_type:
    "int"
    | "boolean"
    | "void"
    | type_identifier

array_type:
    simple_type "[" "]"

type_identifier:
    "identifier"

statements:
    %empty { $$ = new StatementList(); }
    | statements statement { $1->addStatement($2); $$ = $1; }

statement:
    ASSERT "(" expr ")" ";" { $$ = new AssertStatement($3); }
    | local_variable_declaration { $$ = new DeclarationStatement($1); }
    | type "identifier" "=" expr ";" { $$ = new VariableDeclarationAndAssignStatement($2, $4); }
    | "{" statements "}" { $$ = new ScopeStatement($2); }
    | IF "(" expr ")" statement { $$ = new IfThenStatement($3, $5); }
    | IF "(" expr ")" statement ELSE statement { $$ = new IfThenElseStatement($3, $5, $7); }
    | WHILE "(" expr ")" statement { $$ = new WhileStatement($3, $5); }
    | lvalue "=" expr ";" { $$ = new AssignStatement(nullptr, $3); }
    | RETURN expr ";" { $$ = new ReturnStatement($2); }
    | PRINTLN "(" expr ")" ";" { $$ = new PrintlnStatement($3); }
    //| method_invocation ";" { $$ = $1 }

local_variable_declaration:
    variable_declaration { $$ = $1; }

method_invocation:
    expr "." "identifier" "(" args ")"

args:
    %empty
    | expr
    | args "," expr

field_invocation:
    THIS "." "identifier"
    | THIS "." "identifier" "[" expr "]"

lvalue:
    "identifier"
    //| "identifier" "[" expr "]"
    //| field_invocation

expr:
    expr binary_operator expr { $$ = new BinaryExpression($1, $3, $2); }
    | expr "[" expr "]" { $$ = new AccessExpression($1, $3); }
    | expr "." LENGTH { $$ = new LengthExpression($1); }
    | NEW simple_type "[" expr "]" { $$ = new NewArrayExpression("", $4); }
    | NEW type_identifier "(" ")" { $$ = new NewExpression(""); }
    | "!" expr { $$ = new NotExpression($2); }
    | "(" expr ")" { $$ = $2; }
    | "identifier" { $$ = new GetValueExpression($1); }
    | "number" { $$ = new LiteralExpression($1); }
    | THIS { $$ = new ThisExpression(); }
    | TRUE { $$ = new LiteralExpression(true); }
    | FALSE { $$ = new LiteralExpression(false); }
    //| method_invocation { $$ = $1 }
    //| field_invocation

binary_operator:
    "&&" { $$ = new DAmpersandOperator(); }
    | "||" { $$ = new DPipeOperator(); }
    | "<" { $$ = new LTSOperator(); }
    | ">" { $$ = new RTSOperator(); }
    | "==" { $$ = new DAssignOperator(); }
    | "+" { $$ = new PlusOperator(); }
    | "-" { $$ = new MinusOperator(); }
    | "*" { $$ = new StarOperator(); }
    | "/" { $$ = new SlashOperator(); }
    | "%" { $$ = new PercentOperator(); }

%%

void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}