%{
#include <vector>
#include <map>
#include <string>

//#include "CellTypes.h"
//#include "Value.h"
//#include "Expression.h"
#include "Environment.h"
#include "Robot.h"
//#include "Statement.h"
#include "FunctionDef.h"
#include "AssignStmt.h"
#include "ExprStmt.h"
#include "FunctionCallStmt.h"
#include "IfStmt.h"
#include "LoopStmt.h"
//#include "RobotCommandStmt.h"
#include "PrintStmt.h"
#include "AssignArrayStmt.h"
#include "AssignDefStmt.h"
#include "eval.h"
#include "globals.h"
#define RANDOM_FUNC_NAME() ("func_" + std::to_string(__LINE__))

int yylex();
void yyerror(const char *s);
%}

%code requires {
#include "Statement.h"
#include "CellTypes.h"
#include "Value.h"
#include "Expression.h"

enum class RobotCommandType;
}

%define parse.error verbose

%union {
    Statement* stmt;
    std::vector<Statement*>* stmtList;
    RobotCommandType cmdType;
    int iVal;              // INT, BOOL
    char* sVal;            // ID
    CellType cellVal;      // CELL
    Direction dir;         // DIRECTION
    Value* val;
    ValueType typeVal;
    Expression* expr;
}


// Ключевые токены и операторы
%token <iVal> INT BOOL
%token <cellVal> CELL
%token <dir> DIRECTION
%token <sVal> ID
%token <typeVal> TYPE

// терминалы
%token UMINUS LENGTH
%token IF ELSE FROM TO WITH STEP DO FUNCTION END
%token GO PICK DROP LOOK SET GET
%token IN ALL SOME LESS
%token ASSIGN  // <=
%token PLUS MINUS AND OR NOT EQUAL
%token LPAREN RPAREN LQPAREN RQPAREN COMMA
%token SEMICOLON EOL
%token PRINT
%token MOD

// нетерминальные символы и их типы
%type <expr> expression logical_expr number cell
//%type <stmt> robot_command
%type <stmt> control
%type <stmtList> function_body
%type <stmtList> statement_list
%type <stmt> statement
%type <stmt> assignment
//%type <stmt> function_call_stmt
%type <expr> opt_step robot_command_expr function_call_expr
//%type <sVal> function_call_core
%type <stmt> array_assignment


%right UMINUS NOT LENGTH SET GET// Унарный минус
%left PLUS MINUS MOD// лево- правоприоритетные операции
%left AND OR EQUAL UNEQUAL
%left IN LESS
%left ALL SOME

%%

program:
    function_list
;

function_list:
    function
    | function_list EOL function  // EOL
    | /* empty */
;

function:
    FUNCTION ID EOL function_body END
    {
        functionTable[$2] = new FunctionDef{ $2, $4 };
        printf("Function '%s' parsed.\n", $2);
        free($2);
    }
;

function_body:
    {
        env = new Environment(env);
    }
    statement_list
    {
        $$ = $2;
        Environment* old = env->parent;
        delete env;
        env = old;
    }
;

/*opt_eol:
    // empty
    | EOL
;*/

statement_list:
    statement EOL { $$ = new std::vector<Statement*>(); $$->push_back($1); }
    | statement SEMICOLON  { $$ = new std::vector<Statement*>(); $$->push_back($1); }
    | statement_list statement EOL { $1->push_back($2); $$ = $1; }
    | statement_list statement SEMICOLON { $1->push_back($2); $$ = $1; }
    | function EOL { $$ = new std::vector<Statement*>(); }
    | function SEMICOLON { $$ = new std::vector<Statement*>(); }
    | statement_list function EOL { $$ = $1; }
    | statement_list function SEMICOLON { $$ = $1; }
;

statement:
      assignment         { $$ = $1; }
    | control            { $$ = $1; }
    //| robot_command_expr      { $$ = $1; }
    | expression { $$ = new ExprStmt($1); } // может использоваться как возвращаемое значение
    | PRINT expression { $$ = new PrintStmt($2); }
;

assignment:
    ID ASSIGN expression
    {
        $$ = new AssignStmt($1, $3);
        printf("Assign %s\n", $1);
        //print_value($3->evaluate(env)); // отладка
        free($1);
    }

    | TYPE ID ASSIGN expression
    {
        std::string idStr($2);
        free($2);

        // Только для парсинга — временная заглушка
        if (!env->has(idStr))
            env->define(idStr, new Value($1, 0)); // по умолчанию 0 или CELL_UNDEF
        $$ = new AssignDefStmt(idStr, $1, $4); // первое присваивание
        printf("Define %s\n", idStr.c_str());
        //print_value($4->evaluate(env));
    }
    | array_assignment
	/*| ID LQPAREN INT RQPAREN ASSIGN expression
	{
	    $$ = new AssignArrayStmt($1, $3, $6);
	    //env->set($1, $3->evaluate(env)->data[0], $6->evaluate(env)); // Только для парсинга — временная заглушка
        printf("Assign_arr %s[%d]\n", $1, $3);
        //print_value($6->evaluate(env));          // test
        free($1);
    }*/
;

array_assignment:
      ID LQPAREN expression RQPAREN ASSIGN expression
      {
          $$ = new AssignArrayStmt($1, $3, $6);
          printf("Assign_arr %s[.]\n", $1);
          //print_value($6->evaluate(env));
          free($1);
      }
;

expression:
    number
	| cell
    | logical_expr
    | function_call_expr { $$ = $1; }
    | ID LQPAREN expression RQPAREN { $$ = new ArrayAccessExpr($1, $3); free($1); }
    | ID LQPAREN RQPAREN { $$ = new FullVariableExpr($1); free($1); }
    | ID { $$ = new VariableExpr($1); free($1); }
    | LENGTH expression { $$ = new UnaryExpr("length", $2); }
    | expression MOD expression { $$ = new BinaryExpr("%", $1, $3); }
    | expression PLUS expression   { $$ = new BinaryExpr("+", $1, $3); }
    | expression MINUS expression  { $$ = new BinaryExpr("-", $1, $3); }
    | MINUS expression %prec UMINUS { $$ = new UnaryExpr("-", $2); }
    | expression IN expression      { $$ = new BinaryExpr("in", $1, $3); }
    | expression ALL IN expression { $$ = new BinaryExpr("all in", $1, $4); }
    | expression SOME IN expression { $$ = new BinaryExpr("some in", $1, $4); }
    | expression LESS expression { $$ = new BinaryExpr("less", $1, $3); }
    | expression ALL LESS expression { $$ = new BinaryExpr("all less", $1, $4); }
    | expression SOME LESS expression { $$ = new BinaryExpr("some less", $1, $4); }
    | LPAREN expression RPAREN { $$ = $2; }
    | robot_command_expr { $$ = $1; }
;

function_call_expr:
     DO ID {
        printf("Calling function '%s'\n", $2);
        $$ = new FunctionCallExpr($2);
        free($2);
    }
	| DO FUNCTION function_body END {
		std::string name = "func_" + std::to_string(std::rand() % 1000);
		functionTable[name] = new FunctionDef{name , $3 };
        printf("Function (anon) '%s' parsed.\n", name.c_str());
		printf("Calling function '%s'\n", name.c_str());
        $$ = new FunctionCallExpr(name);
        $$ = new FunctionCallExpr(name);
	}
;

number:
    INT { $$ = new ConstantExpr(new Value(ValueType::INT, $1)); }
;

cell:
    CELL { $$ = new ConstantExpr(new Value(ValueType::CELL, $1)); }
;

logical_expr:
    BOOL           { $$ = new ConstantExpr(new Value(ValueType::BOOL, $1)); }
    | expression UNEQUAL expression { $$ = new BinaryExpr("!=", $1, $3); }
    | expression EQUAL expression { $$ = new BinaryExpr("==", $1, $3); }
    | expression AND expression { $$ = new BinaryExpr("and", $1, $3); }
    | expression OR expression  { $$ = new BinaryExpr("or", $1, $3); }
    | NOT expression          { $$ = new UnaryExpr("not", $2); } // логическое отрицание
;

control:
  IF expression function_call_expr ELSE function_call_expr { $$ = new IfStmt($2, dynamic_cast<FunctionCallExpr*>($3), dynamic_cast<FunctionCallExpr*>($5)); printf("If-else called\n"); }
  | IF expression function_call_expr { $$ = new IfStmt($2, dynamic_cast<FunctionCallExpr*>($3)); printf("If called\n"); }
  | FROM expression TO expression opt_step function_call_expr { $$ = new LoopStmt($2, $4, $5, dynamic_cast<FunctionCallExpr*>($6)); printf("From called\n"); }
;

opt_step:
    /* empty */         { $$ = new ConstantExpr(new Value(ValueType::INT, 1)); } // по умолчанию step = 1
    | WITH STEP expression { $$ = $3; }
;

/*function_call_core:
    DO ID {
        $$ = $2;
    }
;*/

/*function_call_stmt:
    function_call_core {
        printf("Calling function (stmt) '%s'\n", $1);
        $$ = new FunctionCallStmt($1);
        free($1);
    }
;*/

robot_command_expr:
      GO DIRECTION       { $$ = new RobotCommandExpr(RobotCommandType::GO, $2, robot); }
    | PICK DIRECTION     { $$ = new RobotCommandExpr(RobotCommandType::PICK, $2, robot); }
    | DROP DIRECTION     { $$ = new RobotCommandExpr(RobotCommandType::DROP, $2, robot); }
    | LOOK DIRECTION     { $$ = new RobotCommandExpr(RobotCommandType::LOOK, $2, robot); }
    | SET expression     { $$ = new RobotCommandExpr(RobotCommandType::SET_VISIBILITY, $2, robot); }
    | GET                { $$ = new RobotCommandExpr(RobotCommandType::GET_VISIBILITY, nullptr, robot); }
;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Parser error: %s\n", s);
}
