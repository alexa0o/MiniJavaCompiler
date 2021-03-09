%skeleton "lalr1.cc"
%require "3.5"

%defines
%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
  #include <string>
  #include "type.h"
  class Scanner;
  class Driver;

  #include "forward_decl.h"
}

%define parse.trace
%define parse.error verbose

%code {
  #include "driver.h"
  #include "location.hh"

  #include "headers.h"

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

%nterm <Expression*> expr method_invocation lvalue
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
%nterm <Type> type simple_type array_type
%nterm <std::string> type_identifier

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
    PUBLIC type "identifier" "(" formals ")" "{" statements "}" { $$ = new MethodDeclaration($2, $3, $8); }

formals:
    %empty
    | variable
    | formals "," variable

variable:
    type "identifier"

variable_declaration:
    type "identifier" ";" { $$ = new VariableDeclaration($1, $2); }

type:
    simple_type { $$ = $1; }
    | array_type { $$ = $1; }

simple_type:
    "int" { $$ = Type("int"); }
    | "boolean" { $$ = Type("bool"); }
    | "void" { $$ = Type(""); }
    | type_identifier { $$ = Type($1); }

array_type:
    simple_type "[" "]" { $1.isArray = true; $$ = $1; }

type_identifier:
    "identifier" { $$ = $1; }

statements:
    %empty { $$ = new StatementList(); }
    | statements statement { $1->addStatement($2); $$ = $1; }

statement:
    ASSERT "(" expr ")" ";" { $$ = new AssertStatement($3); }
    | local_variable_declaration { $$ = new DeclarationStatement($1); }
    | type "identifier" "=" expr ";" { $$ = new VariableDeclarationAndAssignStatement($1, $2, $4); }
    | "{" statements "}" { $$ = new ScopeStatement($2); }
    | IF "(" expr ")" statement { $$ = new IfThenStatement($3, $5); }
    | IF "(" expr ")" statement ELSE statement { $$ = new IfThenElseStatement($3, $5, $7); }
    | WHILE "(" expr ")" statement { $$ = new WhileStatement($3, $5); }
    | lvalue "=" expr ";" { $$ = new AssignStatement($1, $3); }
    | RETURN expr ";" { $$ = new ReturnStatement($2); }
    | PRINTLN "(" expr ")" ";" { $$ = new PrintlnStatement($3); }
    | method_invocation ";" { $$ = new InvocationStatement($1); }

local_variable_declaration:
    variable_declaration { $$ = $1; }

method_invocation:
    expr "." "identifier" "(" args ")" { $$ = new InvocationExpression($1, $3); }

args:
    %empty
    | expr
    | args "," expr

field_invocation:
    THIS "." "identifier"
    | THIS "." "identifier" "[" expr "]"

lvalue:
    "identifier" { $$ = new LValueExpression($1); }
    | "identifier" "[" expr "]" { $$ = new LValueExpression($1, $3); }
    //| field_invocation

expr:
    expr binary_operator expr { $$ = new BinaryExpression($1, $3, $2); }
    | expr "[" expr "]" { $$ = new AccessExpression($1, $3); }
    | expr "." LENGTH { $$ = new LengthExpression($1); }
    | NEW simple_type "[" expr "]" { $$ = new NewArrayExpression($2, $4); }
    | NEW simple_type "(" ")" { $$ = new NewExpression($2); }
    | "!" expr { $$ = new NotExpression($2); }
    | "(" expr ")" { $$ = $2; }
    | "identifier" { $$ = new GetValueExpression($1); }
    | "number" { $$ = new LiteralExpression($1); }
    | THIS { $$ = new ThisExpression(); }
    | TRUE { $$ = new LiteralExpression(true); }
    | FALSE { $$ = new LiteralExpression(false); }
    | method_invocation { $$ = $1; }
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