%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Вспомогательные перечисления
typedef enum { CELL_EMPTY, CELL_WALL, CELL_BOX, CELL_EXIT, CELL_UNDEF } CellType;
typedef enum { DIR_LEFT, DIR_RIGHT, DIR_UP, DIR_DOWN } Direction;

%left PLUS MINUS // лево- правоприоритетные операции
%left AND OR
%right UMINUS  // Унарный минус

// Используется для значений лексем
int yylex();
void yyerror(const char *s);
%}

%union {
    int iVal;            // Целые и булевы значения
    char* sVal;          // Идентификаторы
    CellType cellVal;    // Типы клеток
    Direction dir;       // Направления
}

// Ключевые токены и операторы
%token <iVal> INT BOOL
%token <cellVal> CELL
%token <dir> DIRECTION
%token <sVal> ID

%token IF FROM TO WITH STEP DO FUNCTION END
%token GO PICK DROP LOOK
%token IN ALL SOME LESS
%token ASSIGN  // <=
%token PLUS MINUS AND OR
%token LPAREN RPAREN COMMA
%token SEMICOLON EOL

%type <iVal> expression logical_expr number

%%

program:
    function_list
;

function_list:
    function
    | function_list function
;

function:
    FUNCTION ID statement_list END
    {
        printf("Function '%s' parsed.\n", $2);
        free($2);
    }
;

statement_list:
    statement EOL
    | statement SEMICOLON
    | statement_list statement EOL
    | statement_list statement SEMICOLON
;

statement:
      assignment
    | control
    | robot_command
    | expression // может использоваться как возвращаемое значение
;

assignment:
    ID ASSIGN expression
    {
        printf("Assign %s = %d\n", $1, $3);
        free($1);
    }
;

expression:
    number
    | logical_expr
    | expression PLUS expression   { $$ = $1 + $3; }
    | expression MINUS expression  { $$ = $1 - $3; }
    | MINUS expression %prec UMINUS { $$ = -$2; }
;

number:
    INT { $$ = $1; }
;

logical_expr:
    BOOL           { $$ = $1; }
    | expression AND expression { $$ = ($1 && $3); }
    | expression OR expression  { $$ = ($1 || $3); }
    | MINUS expression          { $$ = !$2; } // логическое отрицание
;

control:
    IF logical_expr DO function_call
    | FROM expression TO expression opt_step DO function_call
;

opt_step:
    /* empty */         { $$ = 1; } // по умолчанию step = 1
    | WITH STEP expression
;

function_call:
    DO ID {
        printf("Calling function '%s'\n", $2);
        free($2);
    }
;

robot_command:
      GO DIRECTION       { printf("go %d\n", $2); }
    | PICK DIRECTION     { printf("pick %d\n", $2); }
    | DROP DIRECTION     { printf("drop %d\n", $2); }
    | LOOK DIRECTION     { printf("look %d\n", $2); }
;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Parser error: %s\n", s);
}
