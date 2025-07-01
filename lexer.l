%{
#include "parser.tab.hpp"
#include "CellTypes.h"
#include "Value.h"
#include <string>
%}

%option noyywrap

DIGIT     [0-9]
SIGN      [-+]?
LETTER    [a-zA-Z]
ID        {LETTER}({LETTER}|{DIGIT}|_)*
FLOAT     {SIGN}{DIGIT}+"."{DIGIT}+([eE][-+]?{DIGIT}+)?
SCI       {SIGN}{DIGIT}+[eE][-+]?{DIGIT}+
INT       {SIGN}{DIGIT}+

%%

"if"                    { return IF; }
"else"                  { return ELSE; }
"from"                  { return FROM; }
"to"                    { return TO; }
"with"                  { return WITH; }
"step"                  { return STEP; }
"do"                    { return DO; }
"function"              { return FUNCTION; }
"end"                   { return END; }
"print"                 { return PRINT; }

"true"                  { yylval.iVal = 1; return BOOL; }
"false"                 { yylval.iVal = 0; return BOOL; }

"EMPTY"                 { yylval.cellVal = CELL_EMPTY; return CELL; }
"WALL"                  { yylval.cellVal = CELL_WALL; return CELL; }
"BOX"                   { yylval.cellVal = CELL_BOX; return CELL; }
"EXIT"                  { yylval.cellVal = CELL_EXIT; return CELL; }
"UNDEF"                 { yylval.cellVal = CELL_UNDEF; return CELL; }

"INT"   { yylval.typeVal = ValueType::INT; return TYPE; }
"BOOL"  { yylval.typeVal = ValueType::BOOL; return TYPE; }
"CELL"  { yylval.typeVal = ValueType::CELL; return TYPE; }


"go"                    { return GO; }
"pick"                  { return PICK; }
"drop"                  { return DROP; }
"look"                  { return LOOK; }
"set"                   { return SET; }
"get"                   { return GET; }

"left"                  { yylval.dir = DIR_LEFT; return DIRECTION; }
"right"                 { yylval.dir = DIR_RIGHT; return DIRECTION; }
"up"                    { yylval.dir = DIR_UP; return DIRECTION; }
"down"                  { yylval.dir = DIR_DOWN; return DIRECTION; }

"in"                    { return IN; }
"all"                   { return ALL; }
"some"                  { return SOME; }
"less"                  { return LESS; }

"length"                { return LENGTH; }
"<="                    { return ASSIGN; }
"=="                    { return EQUAL; }
"!="                    { return UNEQUAL; }
"&"                     { return AND; }
"|"                     { return OR; }
"/"                     { return NOT; }
"-"                     { return MINUS; }
"+"                     { return PLUS; }
"%"                     { return MOD; }
"("                     { return LPAREN; }
")"                     { return RPAREN; }
"["                     { return LQPAREN; }
"]"                     { return RQPAREN; }
","                     { return COMMA; }
"\n"                    { return EOL; }
";"                     { return SEMICOLON; }

{FLOAT}                 { yylval.iVal = atoi(yytext); return INT; }
{SCI}                   { yylval.iVal = atoi(yytext); return INT; }
{INT}                   { yylval.iVal = atoi(yytext); return INT; }

{ID}                    { yylval.sVal = strdup(yytext); return ID; }

[ \t\r]+                { /* skip whitespace */ }
"#".*                   { /* skip comments */ }

.                       { printf("Unknown symbol: %s\n", yytext); exit(1); }

%%
