/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

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

#line 100 "parser.tab.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT = 3,                        /* INT  */
  YYSYMBOL_BOOL = 4,                       /* BOOL  */
  YYSYMBOL_CELL = 5,                       /* CELL  */
  YYSYMBOL_DIRECTION = 6,                  /* DIRECTION  */
  YYSYMBOL_ID = 7,                         /* ID  */
  YYSYMBOL_TYPE = 8,                       /* TYPE  */
  YYSYMBOL_UMINUS = 9,                     /* UMINUS  */
  YYSYMBOL_LENGTH = 10,                    /* LENGTH  */
  YYSYMBOL_IF = 11,                        /* IF  */
  YYSYMBOL_ELSE = 12,                      /* ELSE  */
  YYSYMBOL_FROM = 13,                      /* FROM  */
  YYSYMBOL_TO = 14,                        /* TO  */
  YYSYMBOL_WITH = 15,                      /* WITH  */
  YYSYMBOL_STEP = 16,                      /* STEP  */
  YYSYMBOL_DO = 17,                        /* DO  */
  YYSYMBOL_FUNCTION = 18,                  /* FUNCTION  */
  YYSYMBOL_END = 19,                       /* END  */
  YYSYMBOL_GO = 20,                        /* GO  */
  YYSYMBOL_PICK = 21,                      /* PICK  */
  YYSYMBOL_DROP = 22,                      /* DROP  */
  YYSYMBOL_LOOK = 23,                      /* LOOK  */
  YYSYMBOL_SET = 24,                       /* SET  */
  YYSYMBOL_GET = 25,                       /* GET  */
  YYSYMBOL_IN = 26,                        /* IN  */
  YYSYMBOL_ALL = 27,                       /* ALL  */
  YYSYMBOL_SOME = 28,                      /* SOME  */
  YYSYMBOL_LESS = 29,                      /* LESS  */
  YYSYMBOL_ASSIGN = 30,                    /* ASSIGN  */
  YYSYMBOL_PLUS = 31,                      /* PLUS  */
  YYSYMBOL_MINUS = 32,                     /* MINUS  */
  YYSYMBOL_AND = 33,                       /* AND  */
  YYSYMBOL_OR = 34,                        /* OR  */
  YYSYMBOL_NOT = 35,                       /* NOT  */
  YYSYMBOL_EQUAL = 36,                     /* EQUAL  */
  YYSYMBOL_LPAREN = 37,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 38,                    /* RPAREN  */
  YYSYMBOL_LQPAREN = 39,                   /* LQPAREN  */
  YYSYMBOL_RQPAREN = 40,                   /* RQPAREN  */
  YYSYMBOL_COMMA = 41,                     /* COMMA  */
  YYSYMBOL_SEMICOLON = 42,                 /* SEMICOLON  */
  YYSYMBOL_EOL = 43,                       /* EOL  */
  YYSYMBOL_PRINT = 44,                     /* PRINT  */
  YYSYMBOL_MOD = 45,                       /* MOD  */
  YYSYMBOL_UNEQUAL = 46,                   /* UNEQUAL  */
  YYSYMBOL_YYACCEPT = 47,                  /* $accept  */
  YYSYMBOL_program = 48,                   /* program  */
  YYSYMBOL_function_list = 49,             /* function_list  */
  YYSYMBOL_function = 50,                  /* function  */
  YYSYMBOL_function_body = 51,             /* function_body  */
  YYSYMBOL_52_1 = 52,                      /* $@1  */
  YYSYMBOL_statement_list = 53,            /* statement_list  */
  YYSYMBOL_statement = 54,                 /* statement  */
  YYSYMBOL_assignment = 55,                /* assignment  */
  YYSYMBOL_array_assignment = 56,          /* array_assignment  */
  YYSYMBOL_expression = 57,                /* expression  */
  YYSYMBOL_function_call_expr = 58,        /* function_call_expr  */
  YYSYMBOL_number = 59,                    /* number  */
  YYSYMBOL_cell = 60,                      /* cell  */
  YYSYMBOL_logical_expr = 61,              /* logical_expr  */
  YYSYMBOL_control = 62,                   /* control  */
  YYSYMBOL_opt_step = 63,                  /* opt_step  */
  YYSYMBOL_robot_command_expr = 64         /* robot_command_expr  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   299

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  124

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   301


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    97,    97,   101,   102,   103,   107,   116,   116,   134,
     135,   136,   137,   138,   139,   140,   141,   145,   146,   148,
     149,   153,   161,   173,   185,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   218,   223,   234,   238,   242,
     243,   244,   245,   246,   247,   251,   252,   253,   257,   258,
     276,   277,   278,   279,   280,   281
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INT", "BOOL", "CELL",
  "DIRECTION", "ID", "TYPE", "UMINUS", "LENGTH", "IF", "ELSE", "FROM",
  "TO", "WITH", "STEP", "DO", "FUNCTION", "END", "GO", "PICK", "DROP",
  "LOOK", "SET", "GET", "IN", "ALL", "SOME", "LESS", "ASSIGN", "PLUS",
  "MINUS", "AND", "OR", "NOT", "EQUAL", "LPAREN", "RPAREN", "LQPAREN",
  "RQPAREN", "COMMA", "SEMICOLON", "EOL", "PRINT", "MOD", "UNEQUAL",
  "$accept", "program", "function_list", "function", "function_body",
  "$@1", "statement_list", "statement", "assignment", "array_assignment",
  "expression", "function_call_expr", "number", "cell", "logical_expr",
  "control", "opt_step", "robot_command_expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-47)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -13,     2,    24,     1,   -47,     4,   -47,   -13,   -47,   -47,
      30,    88,   -47,   -47,   -47,   -47,   -10,    23,   114,   114,
     114,    -1,    46,    55,    57,    60,   114,   -47,   114,   114,
     114,   114,    -5,    88,    26,   -47,   -47,   253,   -47,   -47,
     -47,   -47,   -47,   -47,   114,    11,    44,    33,   253,   169,
     126,   -47,   -47,   -47,   -47,   -47,   -47,   253,   253,   253,
     190,   253,   -47,   -47,    28,    42,   -47,   -47,   114,   -22,
      -4,   114,   114,   114,   114,   114,   114,   114,   114,   253,
     -47,   211,   114,    11,    67,   114,    70,   -47,   -47,   -47,
     -47,   -47,    87,   114,   114,   114,   114,    87,    54,    54,
      13,    13,    13,    54,    13,    56,   253,   232,    77,   148,
     -47,    87,    87,    87,    87,   114,   -47,   -47,    86,    77,
     253,   114,   -47,   253
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     0,     0,     2,     3,     0,     1,     0,     7,     4,
       0,     0,     6,    47,    49,    48,    31,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    65,     0,     0,
       0,     0,     0,     8,     0,    17,    23,    19,    28,    25,
      26,    27,    18,    44,     0,     0,     0,    31,    32,     0,
       0,    45,     7,    60,    61,    62,    63,    64,    36,    54,
       0,    20,    14,    13,     0,     0,    10,     9,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    21,
      30,     0,     0,     0,    56,     0,     0,    43,    16,    15,
      12,    11,    37,     0,     0,     0,     0,    40,    34,    35,
      52,    53,    51,    33,    50,    29,    22,     0,     0,    58,
      46,    38,    41,    39,    42,     0,    29,    55,     0,     0,
      24,     0,    57,    59
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -47,   -47,   -47,    12,    52,   -47,   -47,    74,   -47,   -47,
     -18,   -46,   -47,   -47,   -47,   -47,   -47,   -47
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,     4,    10,    11,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,   119,    43
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      48,    49,    50,    84,    93,     1,    51,    94,    57,     5,
      58,    59,    60,    61,    13,    14,    15,    52,    47,     9,
      44,    18,    95,    32,     6,    96,    79,    81,    21,    45,
      46,    22,    23,    24,    25,    26,    27,    62,    63,    68,
      69,    70,    71,    28,     7,    64,    29,     8,    30,    12,
      92,    80,    53,    97,    98,    99,   100,   101,   102,   103,
     104,    54,   117,    55,   106,   107,    56,   109,    66,    67,
      88,    89,    83,   122,    82,   111,   112,   113,   114,   108,
      68,    69,    70,    71,    90,    91,   115,    74,    75,   110,
      76,    13,    14,    15,    21,    16,    17,   120,    18,    19,
      78,    20,   121,   123,    86,    21,     1,    65,    22,    23,
      24,    25,    26,    27,    69,    70,     0,    13,    14,    15,
      28,    47,     0,    29,    18,    30,     0,     0,     0,     0,
       0,    21,    31,     0,    22,    23,    24,    25,    26,    27,
      85,     0,     0,     0,     0,     0,    28,     0,     0,    29,
       0,    30,    68,    69,    70,    71,     0,    72,    73,    74,
      75,     0,    76,   118,     0,     0,     0,     0,     0,     0,
       0,    77,    78,     0,    68,    69,    70,    71,     0,    72,
      73,    74,    75,     0,    76,     0,    21,     0,     0,     0,
       0,     0,     0,    77,    78,    68,    69,    70,    71,     0,
      72,    73,    74,    75,     0,    76,     0,     0,     0,     0,
       0,     0,     0,     0,    77,    78,    68,    69,    70,    71,
       0,    72,    73,    74,    75,     0,    76,     0,    87,     0,
       0,     0,     0,     0,     0,    77,    78,    68,    69,    70,
      71,     0,    72,    73,    74,    75,     0,    76,     0,     0,
       0,   105,     0,     0,     0,     0,    77,    78,    68,    69,
      70,    71,     0,    72,    73,    74,    75,     0,    76,     0,
       0,     0,   116,     0,     0,     0,     0,    77,    78,    68,
      69,    70,    71,     0,    72,    73,    74,    75,     0,    76,
       0,     0,     0,     0,     0,     0,     0,     0,    77,    78
};

static const yytype_int8 yycheck[] =
{
      18,    19,    20,    49,    26,    18,     7,    29,    26,     7,
      28,    29,    30,    31,     3,     4,     5,    18,     7,     7,
      30,    10,    26,    11,     0,    29,    44,    45,    17,    39,
       7,    20,    21,    22,    23,    24,    25,    42,    43,    26,
      27,    28,    29,    32,    43,    33,    35,    43,    37,    19,
      68,    40,     6,    71,    72,    73,    74,    75,    76,    77,
      78,     6,   108,     6,    82,    83,     6,    85,    42,    43,
      42,    43,    39,   119,    30,    93,    94,    95,    96,    12,
      26,    27,    28,    29,    42,    43,    30,    33,    34,    19,
      36,     3,     4,     5,    17,     7,     8,   115,    10,    11,
      46,    13,    16,   121,    52,    17,    18,    33,    20,    21,
      22,    23,    24,    25,    27,    28,    -1,     3,     4,     5,
      32,     7,    -1,    35,    10,    37,    -1,    -1,    -1,    -1,
      -1,    17,    44,    -1,    20,    21,    22,    23,    24,    25,
      14,    -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,    35,
      -1,    37,    26,    27,    28,    29,    -1,    31,    32,    33,
      34,    -1,    36,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    -1,    26,    27,    28,    29,    -1,    31,
      32,    33,    34,    -1,    36,    -1,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    26,    27,    28,    29,    -1,
      31,    32,    33,    34,    -1,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    26,    27,    28,    29,
      -1,    31,    32,    33,    34,    -1,    36,    -1,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    26,    27,    28,
      29,    -1,    31,    32,    33,    34,    -1,    36,    -1,    -1,
      -1,    40,    -1,    -1,    -1,    -1,    45,    46,    26,    27,
      28,    29,    -1,    31,    32,    33,    34,    -1,    36,    -1,
      -1,    -1,    40,    -1,    -1,    -1,    -1,    45,    46,    26,
      27,    28,    29,    -1,    31,    32,    33,    34,    -1,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    18,    48,    49,    50,     7,     0,    43,    43,    50,
      51,    52,    19,     3,     4,     5,     7,     8,    10,    11,
      13,    17,    20,    21,    22,    23,    24,    25,    32,    35,
      37,    44,    50,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    64,    30,    39,     7,     7,    57,    57,
      57,     7,    18,     6,     6,     6,     6,    57,    57,    57,
      57,    57,    42,    43,    50,    54,    42,    43,    26,    27,
      28,    29,    31,    32,    33,    34,    36,    45,    46,    57,
      40,    57,    30,    39,    58,    14,    51,    38,    42,    43,
      42,    43,    57,    26,    29,    26,    29,    57,    57,    57,
      57,    57,    57,    57,    57,    40,    57,    57,    12,    57,
      19,    57,    57,    57,    57,    30,    40,    58,    15,    63,
      57,    16,    58,    57
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    49,    49,    49,    50,    52,    51,    53,
      53,    53,    53,    53,    53,    53,    53,    54,    54,    54,
      54,    55,    55,    55,    56,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    58,    58,    59,    60,    61,
      61,    61,    61,    61,    61,    62,    62,    62,    63,    63,
      64,    64,    64,    64,    64,    64
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     3,     0,     5,     0,     2,     2,
       2,     3,     3,     2,     2,     3,     3,     1,     1,     1,
       2,     3,     4,     1,     6,     1,     1,     1,     1,     4,
       3,     1,     2,     3,     3,     3,     2,     3,     4,     4,
       3,     4,     4,     3,     1,     2,     4,     1,     1,     1,
       3,     3,     3,     3,     2,     5,     3,     6,     0,     3,
       2,     2,     2,     2,     2,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 6: /* function: FUNCTION ID EOL function_body END  */
#line 108 "parser.y"
    {
        functionTable[(yyvsp[-3].sVal)] = new FunctionDef{ (yyvsp[-3].sVal), (yyvsp[-1].stmtList) };
        printf("Function '%s' parsed.\n", (yyvsp[-3].sVal));
        free((yyvsp[-3].sVal));
    }
#line 1538 "parser.tab.cpp"
    break;

  case 7: /* $@1: %empty  */
#line 116 "parser.y"
    {
        env = new Environment(env);
    }
#line 1546 "parser.tab.cpp"
    break;

  case 8: /* function_body: $@1 statement_list  */
#line 120 "parser.y"
    {
        (yyval.stmtList) = (yyvsp[0].stmtList);
        Environment* old = env->parent;
        delete env;
        env = old;
    }
#line 1557 "parser.tab.cpp"
    break;

  case 9: /* statement_list: statement EOL  */
#line 134 "parser.y"
                  { (yyval.stmtList) = new std::vector<Statement*>(); (yyval.stmtList)->push_back((yyvsp[-1].stmt)); }
#line 1563 "parser.tab.cpp"
    break;

  case 10: /* statement_list: statement SEMICOLON  */
#line 135 "parser.y"
                           { (yyval.stmtList) = new std::vector<Statement*>(); (yyval.stmtList)->push_back((yyvsp[-1].stmt)); }
#line 1569 "parser.tab.cpp"
    break;

  case 11: /* statement_list: statement_list statement EOL  */
#line 136 "parser.y"
                                   { (yyvsp[-2].stmtList)->push_back((yyvsp[-1].stmt)); (yyval.stmtList) = (yyvsp[-2].stmtList); }
#line 1575 "parser.tab.cpp"
    break;

  case 12: /* statement_list: statement_list statement SEMICOLON  */
#line 137 "parser.y"
                                         { (yyvsp[-2].stmtList)->push_back((yyvsp[-1].stmt)); (yyval.stmtList) = (yyvsp[-2].stmtList); }
#line 1581 "parser.tab.cpp"
    break;

  case 13: /* statement_list: function EOL  */
#line 138 "parser.y"
                   { (yyval.stmtList) = new std::vector<Statement*>(); }
#line 1587 "parser.tab.cpp"
    break;

  case 14: /* statement_list: function SEMICOLON  */
#line 139 "parser.y"
                         { (yyval.stmtList) = new std::vector<Statement*>(); }
#line 1593 "parser.tab.cpp"
    break;

  case 15: /* statement_list: statement_list function EOL  */
#line 140 "parser.y"
                                  { (yyval.stmtList) = (yyvsp[-2].stmtList); }
#line 1599 "parser.tab.cpp"
    break;

  case 16: /* statement_list: statement_list function SEMICOLON  */
#line 141 "parser.y"
                                        { (yyval.stmtList) = (yyvsp[-2].stmtList); }
#line 1605 "parser.tab.cpp"
    break;

  case 17: /* statement: assignment  */
#line 145 "parser.y"
                         { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1611 "parser.tab.cpp"
    break;

  case 18: /* statement: control  */
#line 146 "parser.y"
                         { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1617 "parser.tab.cpp"
    break;

  case 19: /* statement: expression  */
#line 148 "parser.y"
                 { (yyval.stmt) = new ExprStmt((yyvsp[0].expr)); }
#line 1623 "parser.tab.cpp"
    break;

  case 20: /* statement: PRINT expression  */
#line 149 "parser.y"
                       { (yyval.stmt) = new PrintStmt((yyvsp[0].expr)); }
#line 1629 "parser.tab.cpp"
    break;

  case 21: /* assignment: ID ASSIGN expression  */
#line 154 "parser.y"
    {
        (yyval.stmt) = new AssignStmt((yyvsp[-2].sVal), (yyvsp[0].expr));
        printf("Assign %s\n", (yyvsp[-2].sVal));
        //print_value($3->evaluate(env)); // отладка
        free((yyvsp[-2].sVal));
    }
#line 1640 "parser.tab.cpp"
    break;

  case 22: /* assignment: TYPE ID ASSIGN expression  */
#line 162 "parser.y"
    {
        std::string idStr((yyvsp[-2].sVal));
        free((yyvsp[-2].sVal));

        // Только для парсинга — временная заглушка
        if (!env->has(idStr))
            env->define(idStr, new Value((yyvsp[-3].typeVal), 0)); // по умолчанию 0 или CELL_UNDEF
        (yyval.stmt) = new AssignDefStmt(idStr, (yyvsp[-3].typeVal), (yyvsp[0].expr)); // первое присваивание
        printf("Define %s\n", idStr.c_str());
        //print_value($4->evaluate(env));
    }
#line 1656 "parser.tab.cpp"
    break;

  case 24: /* array_assignment: ID LQPAREN expression RQPAREN ASSIGN expression  */
#line 186 "parser.y"
      {
          (yyval.stmt) = new AssignArrayStmt((yyvsp[-5].sVal), (yyvsp[-3].expr), (yyvsp[0].expr));
          printf("Assign_arr %s[.]\n", (yyvsp[-5].sVal));
          //print_value($6->evaluate(env));
          free((yyvsp[-5].sVal));
      }
#line 1667 "parser.tab.cpp"
    break;

  case 28: /* expression: function_call_expr  */
#line 198 "parser.y"
                         { (yyval.expr) = (yyvsp[0].expr); }
#line 1673 "parser.tab.cpp"
    break;

  case 29: /* expression: ID LQPAREN expression RQPAREN  */
#line 199 "parser.y"
                                    { (yyval.expr) = new ArrayAccessExpr((yyvsp[-3].sVal), (yyvsp[-1].expr)); free((yyvsp[-3].sVal)); }
#line 1679 "parser.tab.cpp"
    break;

  case 30: /* expression: ID LQPAREN RQPAREN  */
#line 200 "parser.y"
                         { (yyval.expr) = new FullVariableExpr((yyvsp[-2].sVal)); free((yyvsp[-2].sVal)); }
#line 1685 "parser.tab.cpp"
    break;

  case 31: /* expression: ID  */
#line 201 "parser.y"
         { (yyval.expr) = new VariableExpr((yyvsp[0].sVal)); free((yyvsp[0].sVal)); }
#line 1691 "parser.tab.cpp"
    break;

  case 32: /* expression: LENGTH expression  */
#line 202 "parser.y"
                        { (yyval.expr) = new UnaryExpr("length", (yyvsp[0].expr)); }
#line 1697 "parser.tab.cpp"
    break;

  case 33: /* expression: expression MOD expression  */
#line 203 "parser.y"
                                { (yyval.expr) = new BinaryExpr("%", (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1703 "parser.tab.cpp"
    break;

  case 34: /* expression: expression PLUS expression  */
#line 204 "parser.y"
                                   { (yyval.expr) = new BinaryExpr("+", (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1709 "parser.tab.cpp"
    break;

  case 35: /* expression: expression MINUS expression  */
#line 205 "parser.y"
                                   { (yyval.expr) = new BinaryExpr("-", (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1715 "parser.tab.cpp"
    break;

  case 36: /* expression: MINUS expression  */
#line 206 "parser.y"
                                    { (yyval.expr) = new UnaryExpr("-", (yyvsp[0].expr)); }
#line 1721 "parser.tab.cpp"
    break;

  case 37: /* expression: expression IN expression  */
#line 207 "parser.y"
                                    { (yyval.expr) = new BinaryExpr("in", (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1727 "parser.tab.cpp"
    break;

  case 38: /* expression: expression ALL IN expression  */
#line 208 "parser.y"
                                   { (yyval.expr) = new BinaryExpr("all in", (yyvsp[-3].expr), (yyvsp[0].expr)); }
#line 1733 "parser.tab.cpp"
    break;

  case 39: /* expression: expression SOME IN expression  */
#line 209 "parser.y"
                                    { (yyval.expr) = new BinaryExpr("some in", (yyvsp[-3].expr), (yyvsp[0].expr)); }
#line 1739 "parser.tab.cpp"
    break;

  case 40: /* expression: expression LESS expression  */
#line 210 "parser.y"
                                 { (yyval.expr) = new BinaryExpr("less", (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1745 "parser.tab.cpp"
    break;

  case 41: /* expression: expression ALL LESS expression  */
#line 211 "parser.y"
                                     { (yyval.expr) = new BinaryExpr("all less", (yyvsp[-3].expr), (yyvsp[0].expr)); }
#line 1751 "parser.tab.cpp"
    break;

  case 42: /* expression: expression SOME LESS expression  */
#line 212 "parser.y"
                                      { (yyval.expr) = new BinaryExpr("some less", (yyvsp[-3].expr), (yyvsp[0].expr)); }
#line 1757 "parser.tab.cpp"
    break;

  case 43: /* expression: LPAREN expression RPAREN  */
#line 213 "parser.y"
                               { (yyval.expr) = (yyvsp[-1].expr); }
#line 1763 "parser.tab.cpp"
    break;

  case 44: /* expression: robot_command_expr  */
#line 214 "parser.y"
                         { (yyval.expr) = (yyvsp[0].expr); }
#line 1769 "parser.tab.cpp"
    break;

  case 45: /* function_call_expr: DO ID  */
#line 218 "parser.y"
           {
        printf("Calling function '%s'\n", (yyvsp[0].sVal));
        (yyval.expr) = new FunctionCallExpr((yyvsp[0].sVal));
        free((yyvsp[0].sVal));
    }
#line 1779 "parser.tab.cpp"
    break;

  case 46: /* function_call_expr: DO FUNCTION function_body END  */
#line 223 "parser.y"
                                        {
		std::string name = "func_" + std::to_string(std::rand() % 1000);
		functionTable[name] = new FunctionDef{name , (yyvsp[-1].stmtList) };
        printf("Function (anon) '%s' parsed.\n", name.c_str());
		printf("Calling function '%s'\n", name.c_str());
        (yyval.expr) = new FunctionCallExpr(name);
        (yyval.expr) = new FunctionCallExpr(name);
	}
#line 1792 "parser.tab.cpp"
    break;

  case 47: /* number: INT  */
#line 234 "parser.y"
        { (yyval.expr) = new ConstantExpr(new Value(ValueType::INT, (yyvsp[0].iVal))); }
#line 1798 "parser.tab.cpp"
    break;

  case 48: /* cell: CELL  */
#line 238 "parser.y"
         { (yyval.expr) = new ConstantExpr(new Value(ValueType::CELL, (yyvsp[0].cellVal))); }
#line 1804 "parser.tab.cpp"
    break;

  case 49: /* logical_expr: BOOL  */
#line 242 "parser.y"
                   { (yyval.expr) = new ConstantExpr(new Value(ValueType::BOOL, (yyvsp[0].iVal))); }
#line 1810 "parser.tab.cpp"
    break;

  case 50: /* logical_expr: expression UNEQUAL expression  */
#line 243 "parser.y"
                                    { (yyval.expr) = new BinaryExpr("!=", (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1816 "parser.tab.cpp"
    break;

  case 51: /* logical_expr: expression EQUAL expression  */
#line 244 "parser.y"
                                  { (yyval.expr) = new BinaryExpr("==", (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1822 "parser.tab.cpp"
    break;

  case 52: /* logical_expr: expression AND expression  */
#line 245 "parser.y"
                                { (yyval.expr) = new BinaryExpr("and", (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1828 "parser.tab.cpp"
    break;

  case 53: /* logical_expr: expression OR expression  */
#line 246 "parser.y"
                                { (yyval.expr) = new BinaryExpr("or", (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1834 "parser.tab.cpp"
    break;

  case 54: /* logical_expr: NOT expression  */
#line 247 "parser.y"
                              { (yyval.expr) = new UnaryExpr("not", (yyvsp[0].expr)); }
#line 1840 "parser.tab.cpp"
    break;

  case 55: /* control: IF expression function_call_expr ELSE function_call_expr  */
#line 251 "parser.y"
                                                           { (yyval.stmt) = new IfStmt((yyvsp[-3].expr), dynamic_cast<FunctionCallExpr*>((yyvsp[-2].expr)), dynamic_cast<FunctionCallExpr*>((yyvsp[0].expr))); printf("If-else called\n"); }
#line 1846 "parser.tab.cpp"
    break;

  case 56: /* control: IF expression function_call_expr  */
#line 252 "parser.y"
                                     { (yyval.stmt) = new IfStmt((yyvsp[-1].expr), dynamic_cast<FunctionCallExpr*>((yyvsp[0].expr))); printf("If called\n"); }
#line 1852 "parser.tab.cpp"
    break;

  case 57: /* control: FROM expression TO expression opt_step function_call_expr  */
#line 253 "parser.y"
                                                              { (yyval.stmt) = new LoopStmt((yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[-1].expr), dynamic_cast<FunctionCallExpr*>((yyvsp[0].expr))); printf("From called\n"); }
#line 1858 "parser.tab.cpp"
    break;

  case 58: /* opt_step: %empty  */
#line 257 "parser.y"
                        { (yyval.expr) = new ConstantExpr(new Value(ValueType::INT, 1)); }
#line 1864 "parser.tab.cpp"
    break;

  case 59: /* opt_step: WITH STEP expression  */
#line 258 "parser.y"
                           { (yyval.expr) = (yyvsp[0].expr); }
#line 1870 "parser.tab.cpp"
    break;

  case 60: /* robot_command_expr: GO DIRECTION  */
#line 276 "parser.y"
                         { (yyval.expr) = new RobotCommandExpr(RobotCommandType::GO, (yyvsp[0].dir), robot); }
#line 1876 "parser.tab.cpp"
    break;

  case 61: /* robot_command_expr: PICK DIRECTION  */
#line 277 "parser.y"
                         { (yyval.expr) = new RobotCommandExpr(RobotCommandType::PICK, (yyvsp[0].dir), robot); }
#line 1882 "parser.tab.cpp"
    break;

  case 62: /* robot_command_expr: DROP DIRECTION  */
#line 278 "parser.y"
                         { (yyval.expr) = new RobotCommandExpr(RobotCommandType::DROP, (yyvsp[0].dir), robot); }
#line 1888 "parser.tab.cpp"
    break;

  case 63: /* robot_command_expr: LOOK DIRECTION  */
#line 279 "parser.y"
                         { (yyval.expr) = new RobotCommandExpr(RobotCommandType::LOOK, (yyvsp[0].dir), robot); }
#line 1894 "parser.tab.cpp"
    break;

  case 64: /* robot_command_expr: SET expression  */
#line 280 "parser.y"
                         { (yyval.expr) = new RobotCommandExpr(RobotCommandType::SET_VISIBILITY, (yyvsp[0].expr), robot); }
#line 1900 "parser.tab.cpp"
    break;

  case 65: /* robot_command_expr: GET  */
#line 281 "parser.y"
                         { (yyval.expr) = new RobotCommandExpr(RobotCommandType::GET_VISIBILITY, nullptr, robot); }
#line 1906 "parser.tab.cpp"
    break;


#line 1910 "parser.tab.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 284 "parser.y"


void yyerror(const char *s) {
    fprintf(stderr, "Parser error: %s\n", s);
}
