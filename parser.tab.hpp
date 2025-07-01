/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_HPP_INCLUDED
# define YY_YY_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 30 "parser.y"

#include "Statement.h"
#include "CellTypes.h"
#include "Value.h"
#include "Expression.h"

enum class RobotCommandType;

#line 58 "parser.tab.hpp"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INT = 258,                     /* INT  */
    BOOL = 259,                    /* BOOL  */
    CELL = 260,                    /* CELL  */
    DIRECTION = 261,               /* DIRECTION  */
    ID = 262,                      /* ID  */
    TYPE = 263,                    /* TYPE  */
    UMINUS = 264,                  /* UMINUS  */
    LENGTH = 265,                  /* LENGTH  */
    IF = 266,                      /* IF  */
    ELSE = 267,                    /* ELSE  */
    FROM = 268,                    /* FROM  */
    TO = 269,                      /* TO  */
    WITH = 270,                    /* WITH  */
    STEP = 271,                    /* STEP  */
    DO = 272,                      /* DO  */
    FUNCTION = 273,                /* FUNCTION  */
    END = 274,                     /* END  */
    GO = 275,                      /* GO  */
    PICK = 276,                    /* PICK  */
    DROP = 277,                    /* DROP  */
    LOOK = 278,                    /* LOOK  */
    SET = 279,                     /* SET  */
    GET = 280,                     /* GET  */
    IN = 281,                      /* IN  */
    ALL = 282,                     /* ALL  */
    SOME = 283,                    /* SOME  */
    LESS = 284,                    /* LESS  */
    ASSIGN = 285,                  /* ASSIGN  */
    PLUS = 286,                    /* PLUS  */
    MINUS = 287,                   /* MINUS  */
    AND = 288,                     /* AND  */
    OR = 289,                      /* OR  */
    NOT = 290,                     /* NOT  */
    EQUAL = 291,                   /* EQUAL  */
    LPAREN = 292,                  /* LPAREN  */
    RPAREN = 293,                  /* RPAREN  */
    LQPAREN = 294,                 /* LQPAREN  */
    RQPAREN = 295,                 /* RQPAREN  */
    COMMA = 296,                   /* COMMA  */
    SEMICOLON = 297,               /* SEMICOLON  */
    EOL = 298,                     /* EOL  */
    PRINT = 299,                   /* PRINT  */
    MOD = 300,                     /* MOD  */
    UNEQUAL = 301                  /* UNEQUAL  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 41 "parser.y"

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

#line 134 "parser.tab.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_HPP_INCLUDED  */
