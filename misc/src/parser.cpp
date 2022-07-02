/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "Parser.y"

  #include <stdio.h>
  #include <string>
  #include <stdlib.h>
  int lineNumber = 0;
  int yydebug = 1;

  extern int yylineno;
  extern int yylex();
  extern char *yytext;

  void yyerror(const char *s) { 
      printf("Syntax error on line: %d\n", yylineno);
  }

#line 86 "./src/parser.cpp"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_INC_PARSER_HPP_INCLUDED
# define YY_YY_INC_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 17 "Parser.y"

   #include "../inc/Types.h"
  #include "../inc/Directive.hpp"
  #include "../inc/Argument.hpp"
  #include "../inc/Instruction.hpp"
  #include "../inc/Line.hpp"
  #include "../inc/Label.hpp"
  #include "../inc/Lines.hpp"

  extern Lines* lineVec;  

#line 141 "./src/parser.cpp"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    REGISTER = 258,
    SYMBOL = 259,
    NUMBER = 260,
    GLOBAL = 261,
    EXTERN = 262,
    SECTION = 263,
    WORD = 264,
    SKIP = 265,
    ASCII = 266,
    EQU = 267,
    END = 268,
    HALT = 269,
    INT = 270,
    RET = 271,
    IRET = 272,
    CALL = 273,
    JMP = 274,
    JEQ = 275,
    JNE = 276,
    JGT = 277,
    PUSH = 278,
    POP = 279,
    XCHG = 280,
    ADD = 281,
    SUB = 282,
    MUL = 283,
    DIV = 284,
    CMP = 285,
    NOT = 286,
    AND = 287,
    OR = 288,
    XOR = 289,
    TEST = 290,
    SHL = 291,
    SHR = 292,
    LDR = 293,
    STR = 294,
    IP = 295,
    PSW = 296,
    SP = 297,
    COMMENT = 298,
    COMMA = 299,
    DOT = 300,
    COLON = 301,
    PLUS = 302,
    MINUS = 303,
    STAR = 304,
    MOD = 305,
    DOLLAR = 306,
    LBRACKET = 307,
    RBRACKET = 308,
    NEW_LINE = 309,
    QUOTATION_MARK = 310
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 32 "Parser.y"

  std::string *symbol;
  int token;
  int number;
  char reg;

  Directive* directive;
  Instruction* instruction;
  Line* line;
  // Argument* argument;
  Label* label;
  Lines* lines;

  std::vector<SymbolListElement*>* symbolList;
  std::vector<SymbolListElement*>* symbolLiterallList;

  Argument *jumpOperand;
  Argument *dataOperand;


#line 229 "./src/parser.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_INC_PARSER_HPP_INCLUDED  */



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
typedef yytype_uint8 yy_state_t;

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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


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
#define YYFINAL  81
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   199

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  11
/* YYNRULES -- Number of rules.  */
#define YYNRULES  74
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  164

#define YYUNDEFTOK  2
#define YYMAXUTOK   310


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    82,    82,    87,    92,    98,   101,   105,   110,   115,
     120,   125,   130,   135,   140,   145,   150,   157,   162,   165,
     168,   171,   174,   177,   180,   185,   189,   194,   198,   202,
     205,   210,   213,   216,   219,   222,   225,   228,   231,   234,
     237,   240,   243,   246,   249,   252,   255,   258,   261,   264,
     267,   270,   273,   276,   279,   282,   285,   291,   294,   297,
     300,   303,   306,   309,   312,   315,   321,   324,   327,   330,
     333,   336,   339,   342,   345
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "REGISTER", "SYMBOL", "NUMBER", "GLOBAL",
  "EXTERN", "SECTION", "WORD", "SKIP", "ASCII", "EQU", "END", "HALT",
  "INT", "RET", "IRET", "CALL", "JMP", "JEQ", "JNE", "JGT", "PUSH", "POP",
  "XCHG", "ADD", "SUB", "MUL", "DIV", "CMP", "NOT", "AND", "OR", "XOR",
  "TEST", "SHL", "SHR", "LDR", "STR", "IP", "PSW", "SP", "COMMENT",
  "COMMA", "DOT", "COLON", "PLUS", "MINUS", "STAR", "MOD", "DOLLAR",
  "LBRACKET", "RBRACKET", "NEW_LINE", "QUOTATION_MARK", "$accept",
  "program", "lines", "line", "label", "directive", "symbolList",
  "symbolLiterallList", "instruction", "dataOperand", "jumpOperand", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310
};
# endif

#define YYPACT_NINF (-46)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -4,   -45,     4,     4,    -2,    86,    75,    41,   -46,   -46,
     111,   -46,   -46,    74,    74,    74,    74,    74,   112,   113,
     114,   115,   116,   117,   118,   119,   122,   123,   124,   125,
     126,   127,   128,   129,   130,    80,   -46,   135,    -4,   -46,
      38,    39,    43,   -46,   -46,    92,    92,   133,   -46,   -46,
      94,   -46,   136,   -46,   -46,   -46,    37,   137,   -46,   -46,
     -46,   -46,   -46,   -46,   -46,    95,    98,    99,   100,   101,
     103,   -46,   105,   107,   109,   110,   120,   121,   131,   132,
     -46,   -46,   -46,    96,   -46,    44,    45,   134,   -46,   138,
     -46,   142,   -46,   102,    93,   -46,   -46,   -46,   149,   -46,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   163,
     164,   165,    33,    33,   -46,   139,   -46,   140,   -46,   -46,
     -46,   -46,   -46,   -46,   -46,    47,   -46,   -46,   -46,   -46,
     -46,   -46,   -46,   -46,   -46,   -46,   -46,   -46,   -46,   -46,
     -46,   166,   104,   168,   -46,   -46,   -46,   -46,   106,   -46,
     -46,   -46,   -46,    48,   143,   144,   108,   -46,   -46,   -46,
     145,   146,   -46,   -46
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,    24,    31,
       0,    33,    32,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     5,     0,     2,     3,
       0,     0,     0,    17,    25,    18,    20,     0,    27,    28,
      22,    23,     0,    34,    67,    66,     0,     0,    50,    51,
      52,    53,    54,    35,    36,     0,     0,     0,     0,     0,
       0,    43,     0,     0,     0,     0,     0,     0,     0,     0,
       6,     1,     4,     0,     7,     0,     0,     0,    14,     0,
      13,     0,    21,     0,     0,    71,    70,    69,     0,    68,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    10,     0,     8,     0,     9,    16,
      15,    26,    29,    30,    19,     0,    37,    38,    39,    40,
      41,    42,    44,    45,    46,    47,    48,    49,    62,    60,
      59,     0,     0,     0,    55,    56,    11,    12,     0,    72,
      61,    58,    57,     0,     0,     0,     0,    63,    74,    73,
       0,     0,    65,    64
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -46,   -46,   -46,   141,   -46,   147,   169,   -46,   150,    56,
      88
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    37,    38,    39,    40,    41,    45,    50,    42,   144,
      58
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       1,    43,     2,     3,     4,     5,     6,     7,    44,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,   138,   139,   140,    35,
      95,    96,    97,    47,     2,     3,     4,     5,     6,     7,
      36,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    54,    55,
      51,    83,    87,   141,   142,   143,    89,   115,   117,    98,
      48,    49,    84,    88,   148,   156,    52,    90,   116,   118,
     149,   157,    59,    60,    61,    62,   122,   123,   151,   152,
     154,   155,   160,   161,    53,    63,    64,    65,    66,    67,
      68,    69,    70,    56,    57,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    91,    92,    93,   100,
      94,    99,   101,   102,   103,   104,   121,   105,   124,   106,
     114,   107,   125,   108,   109,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   110,   111,   135,   136,   137,   145,
     150,   153,    46,     0,     0,   112,   113,     0,     0,    82,
       0,     0,     0,     0,     0,     0,     0,    85,   119,     0,
      86,     0,   120,   146,   147,     0,   158,   159,   162,   163
};

static const yytype_int8 yycheck[] =
{
       4,    46,     6,     7,     8,     9,    10,    11,     4,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,     3,     4,     5,    43,
       3,     4,     5,    45,     6,     7,     8,     9,    10,    11,
      54,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,     4,     5,
       5,    43,    43,    50,    51,    52,    43,    43,    43,    52,
       4,     5,    54,    54,    47,    47,    55,    54,    54,    54,
      53,    53,    14,    15,    16,    17,     4,     5,     4,     5,
       4,     5,     4,     5,     3,     3,     3,     3,     3,     3,
       3,     3,     3,    49,    50,     3,     3,     3,     3,     3,
       3,     3,     3,     3,    54,     0,    44,     4,    44,    44,
       4,     4,    44,    44,    44,    44,     4,    44,    55,    44,
      54,    44,     3,    44,    44,     3,     3,     3,     3,     3,
       3,     3,     3,     3,    44,    44,     3,     3,     3,   113,
       4,     3,     3,    -1,    -1,    44,    44,    -1,    -1,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    54,    -1,
      40,    -1,    54,    54,    54,    -1,    53,    53,    53,    53
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,     6,     7,     8,     9,    10,    11,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    43,    54,    57,    58,    59,
      60,    61,    64,    46,     4,    62,    62,    45,     4,     5,
      63,     5,    55,     3,     4,     5,    49,    50,    66,    66,
      66,    66,    66,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
      54,     0,    59,    43,    54,    61,    64,    43,    54,    43,
      54,    44,     4,    44,     4,     3,     4,     5,    52,     4,
      44,    44,    44,    44,    44,    44,    44,    44,    44,    44,
      44,    44,    44,    44,    54,    43,    54,    43,    54,    54,
      54,     4,     4,     5,    55,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     4,
       5,    50,    51,    52,    65,    65,    54,    54,    47,    53,
       4,     4,     5,     3,     4,     5,    47,    53,    53,    53,
       4,     5,    53,    53
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    56,    57,    58,    58,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    60,    61,    61,
      61,    61,    61,    61,    61,    62,    62,    63,    63,    63,
      63,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    66,    66,    66,    66,
      66,    66,    66,    66,    66
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     2,     2,     3,     3,
       3,     4,     4,     2,     2,     3,     3,     2,     2,     4,
       2,     3,     2,     2,     1,     1,     3,     1,     1,     3,
       3,     1,     1,     1,     2,     2,     2,     4,     4,     4,
       4,     4,     4,     2,     4,     4,     4,     4,     4,     4,
       2,     2,     2,     2,     2,     4,     4,     2,     2,     1,
       1,     2,     1,     3,     5,     5,     1,     1,     2,     2,
       2,     2,     4,     6,     6
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
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
#  endif
# endif

# ifndef yytnamerr
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
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
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
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
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
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
  case 2:
#line 82 "Parser.y"
       {
    lineVec = (yyvsp[0].lines);
  }
#line 1520 "./src/parser.cpp"
    break;

  case 3:
#line 87 "Parser.y"
      {
    (yyval.lines) = new Lines();
    if((yyvsp[0].line) != nullptr)
      (yyval.lines)->putLine((yyvsp[0].line));
  }
#line 1530 "./src/parser.cpp"
    break;

  case 4:
#line 92 "Parser.y"
              {
    if((yyvsp[0].line) != nullptr)
      (yyvsp[-1].lines)->putLine((yyvsp[0].line));
  }
#line 1539 "./src/parser.cpp"
    break;

  case 5:
#line 98 "Parser.y"
          {
    (yyval.line) = nullptr;
  }
#line 1547 "./src/parser.cpp"
    break;

  case 6:
#line 101 "Parser.y"
                    {
    (yyval.line) = nullptr;
    lineNumber++;
  }
#line 1556 "./src/parser.cpp"
    break;

  case 7:
#line 105 "Parser.y"
                  {
    (yyval.line) = new Line((yyvsp[-1].label));
    (yyval.line)->setLineNumber(lineNumber);
    lineNumber++;
  }
#line 1566 "./src/parser.cpp"
    break;

  case 8:
#line 110 "Parser.y"
                            {
    (yyval.line) = new Line((yyvsp[-2].label), (yyvsp[-1].directive));
    (yyval.line)->setLineNumber(lineNumber);
    lineNumber++;
  }
#line 1576 "./src/parser.cpp"
    break;

  case 9:
#line 115 "Parser.y"
                              {
    (yyval.line) = new Line((yyvsp[-2].label), (yyvsp[-1].instruction));
    (yyval.line)->setLineNumber(lineNumber);
    lineNumber++;
  }
#line 1586 "./src/parser.cpp"
    break;

  case 10:
#line 120 "Parser.y"
                          {
    (yyval.line) = new Line((yyvsp[-2].label));
    (yyval.line)->setLineNumber(lineNumber);
    lineNumber++;
  }
#line 1596 "./src/parser.cpp"
    break;

  case 11:
#line 125 "Parser.y"
                                    {
    (yyval.line) = new Line((yyvsp[-3].label),(yyvsp[-2].directive));
    (yyval.line)->setLineNumber(lineNumber);
    lineNumber++;
  }
#line 1606 "./src/parser.cpp"
    break;

  case 12:
#line 130 "Parser.y"
                                      {
    (yyval.line) = new Line((yyvsp[-3].label),(yyvsp[-2].instruction));
    (yyval.line)->setLineNumber(lineNumber);
    lineNumber++;
  }
#line 1616 "./src/parser.cpp"
    break;

  case 13:
#line 135 "Parser.y"
                        {
    (yyval.line) = new Line((yyvsp[-1].instruction));
    (yyval.line)->setLineNumber(lineNumber);
    lineNumber++;
  }
#line 1626 "./src/parser.cpp"
    break;

  case 14:
#line 140 "Parser.y"
                      {
    (yyval.line) = new Line((yyvsp[-1].directive));
    (yyval.line)->setLineNumber(lineNumber);
    lineNumber++;
  }
#line 1636 "./src/parser.cpp"
    break;

  case 15:
#line 145 "Parser.y"
                                {
    (yyval.line) = new Line((yyvsp[-2].instruction));
    (yyval.line)->setLineNumber(lineNumber);
    lineNumber++;
  }
#line 1646 "./src/parser.cpp"
    break;

  case 16:
#line 150 "Parser.y"
                              {
    (yyval.line) = new Line((yyvsp[-2].directive));
    (yyval.line)->setLineNumber(lineNumber);
    lineNumber++;
  }
#line 1656 "./src/parser.cpp"
    break;

  case 17:
#line 157 "Parser.y"
              {
    (yyval.label) = new Label((yyvsp[-1].symbol));
  }
#line 1664 "./src/parser.cpp"
    break;

  case 18:
#line 162 "Parser.y"
                   {
    (yyval.directive) = new Directive(GLOBAL_TYPE,(yyvsp[0].symbolList));
  }
#line 1672 "./src/parser.cpp"
    break;

  case 19:
#line 165 "Parser.y"
                                              {
    (yyval.directive) = new Directive(ASCII_TYPE,(yyvsp[-1].symbol));
  }
#line 1680 "./src/parser.cpp"
    break;

  case 20:
#line 168 "Parser.y"
                     {
    (yyval.directive) = new Directive(EXTERN_TYPE,(yyvsp[0].symbolList));
  }
#line 1688 "./src/parser.cpp"
    break;

  case 21:
#line 171 "Parser.y"
                      {
    (yyval.directive) = new Directive(SECTION_TYPE,(yyvsp[0].symbol));
  }
#line 1696 "./src/parser.cpp"
    break;

  case 22:
#line 174 "Parser.y"
                           {
    (yyval.directive) = new Directive(WORD_TYPE,(yyvsp[0].symbolLiterallList));
  }
#line 1704 "./src/parser.cpp"
    break;

  case 23:
#line 177 "Parser.y"
               {
    (yyval.directive) = new Directive(SKIP_TYPE,(yyvsp[0].number));
  }
#line 1712 "./src/parser.cpp"
    break;

  case 24:
#line 180 "Parser.y"
       {
    (yyval.directive) = new Directive(END_TYPE);
  }
#line 1720 "./src/parser.cpp"
    break;

  case 25:
#line 185 "Parser.y"
        {
    (yyval.symbolList) = new std::vector<SymbolListElement*>();
    (yyval.symbolList)->push_back(new SymbolListElement(SYMBOL_TYPE,(yyvsp[0].symbol)));
  }
#line 1729 "./src/parser.cpp"
    break;

  case 26:
#line 189 "Parser.y"
                           {
    (yyvsp[-2].symbolList)->push_back(new SymbolListElement(SYMBOL_TYPE,(yyvsp[0].symbol)));
  }
#line 1737 "./src/parser.cpp"
    break;

  case 27:
#line 194 "Parser.y"
        {
    (yyval.symbolLiterallList) = new std::vector<SymbolListElement*>();
    (yyval.symbolLiterallList)->push_back(new SymbolListElement(SYMBOL_TYPE,(yyvsp[0].symbol)));
  }
#line 1746 "./src/parser.cpp"
    break;

  case 28:
#line 198 "Parser.y"
          {
    (yyval.symbolLiterallList) = new std::vector<SymbolListElement*>();
    (yyval.symbolLiterallList)->push_back(new SymbolListElement(LITERAL_TYPE,(yyvsp[0].number)));
  }
#line 1755 "./src/parser.cpp"
    break;

  case 29:
#line 202 "Parser.y"
                                   {
    (yyvsp[-2].symbolLiterallList)->push_back(new SymbolListElement(SYMBOL_TYPE,(yyvsp[0].symbol)));
  }
#line 1763 "./src/parser.cpp"
    break;

  case 30:
#line 205 "Parser.y"
                                   {
    (yyvsp[-2].symbolLiterallList)->push_back(new SymbolListElement(LITERAL_TYPE,(yyvsp[0].number)));
  }
#line 1771 "./src/parser.cpp"
    break;

  case 31:
#line 210 "Parser.y"
      {
    (yyval.instruction) = new Instruction(HALT_TYPE);
  }
#line 1779 "./src/parser.cpp"
    break;

  case 32:
#line 213 "Parser.y"
        {
    (yyval.instruction) = new Instruction(IRET_TYPE);
  }
#line 1787 "./src/parser.cpp"
    break;

  case 33:
#line 216 "Parser.y"
       {
    (yyval.instruction) = new Instruction(RET_TYPE);
  }
#line 1795 "./src/parser.cpp"
    break;

  case 34:
#line 219 "Parser.y"
                {
    (yyval.instruction) = new Instruction(INT_TYPE, new Argument(REGISTER_TYPE,(yyvsp[0].reg)));
  }
#line 1803 "./src/parser.cpp"
    break;

  case 35:
#line 222 "Parser.y"
                 {
    (yyval.instruction) = new Instruction(PUSH_TYPE, new Argument(REGISTER_TYPE,(yyvsp[0].reg)),new Argument(DATA_OPERAND_REGMEM,(char)6));
  }
#line 1811 "./src/parser.cpp"
    break;

  case 36:
#line 225 "Parser.y"
                {
    (yyval.instruction) = new Instruction(POP_TYPE, new Argument(REGISTER_TYPE,(yyvsp[0].reg)),new Argument(DATA_OPERAND_REGMEM,(char)6));
  }
#line 1819 "./src/parser.cpp"
    break;

  case 37:
#line 228 "Parser.y"
                                {
    (yyval.instruction) = new Instruction(XCHG_TYPE, new Argument(REGISTER_TYPE,(yyvsp[-2].reg)), new Argument(REGISTER_TYPE,(yyvsp[0].reg)));
  }
#line 1827 "./src/parser.cpp"
    break;

  case 38:
#line 231 "Parser.y"
                               {
    (yyval.instruction) = new Instruction(ADD_TYPE, new Argument(REGISTER_TYPE,(yyvsp[-2].reg)), new Argument(REGISTER_TYPE,(yyvsp[0].reg)));
  }
#line 1835 "./src/parser.cpp"
    break;

  case 39:
#line 234 "Parser.y"
                               {
    (yyval.instruction) = new Instruction(SUB_TYPE, new Argument(REGISTER_TYPE,(yyvsp[-2].reg)), new Argument(REGISTER_TYPE,(yyvsp[0].reg)));
  }
#line 1843 "./src/parser.cpp"
    break;

  case 40:
#line 237 "Parser.y"
                               {
    (yyval.instruction) = new Instruction(MUL_TYPE, new Argument(REGISTER_TYPE,(yyvsp[-2].reg)), new Argument(REGISTER_TYPE,(yyvsp[0].reg)));
  }
#line 1851 "./src/parser.cpp"
    break;

  case 41:
#line 240 "Parser.y"
                               {
    (yyval.instruction) = new Instruction(DIV_TYPE, new Argument(REGISTER_TYPE,(yyvsp[-2].reg)), new Argument(REGISTER_TYPE,(yyvsp[0].reg)));
  }
#line 1859 "./src/parser.cpp"
    break;

  case 42:
#line 243 "Parser.y"
                               {
    (yyval.instruction) = new Instruction(CMP_TYPE, new Argument(REGISTER_TYPE,(yyvsp[-2].reg)), new Argument(REGISTER_TYPE,(yyvsp[0].reg)));
  }
#line 1867 "./src/parser.cpp"
    break;

  case 43:
#line 246 "Parser.y"
                {
    (yyval.instruction) = new Instruction(NOT_TYPE, new Argument(REGISTER_TYPE,(yyvsp[0].reg)));
  }
#line 1875 "./src/parser.cpp"
    break;

  case 44:
#line 249 "Parser.y"
                               {
    (yyval.instruction) = new Instruction(AND_TYPE, new Argument(REGISTER_TYPE,(yyvsp[-2].reg)), new Argument(REGISTER_TYPE,(yyvsp[0].reg)));
  }
#line 1883 "./src/parser.cpp"
    break;

  case 45:
#line 252 "Parser.y"
                              {
    (yyval.instruction) = new Instruction(OR_TYPE, new Argument(REGISTER_TYPE,(yyvsp[-2].reg)), new Argument(REGISTER_TYPE,(yyvsp[0].reg)));
  }
#line 1891 "./src/parser.cpp"
    break;

  case 46:
#line 255 "Parser.y"
                               {
    (yyval.instruction) = new Instruction(XOR_TYPE, new Argument(REGISTER_TYPE,(yyvsp[-2].reg)), new Argument(REGISTER_TYPE,(yyvsp[0].reg)));
  }
#line 1899 "./src/parser.cpp"
    break;

  case 47:
#line 258 "Parser.y"
                                {
    (yyval.instruction) = new Instruction(TEST_TYPE, new Argument(REGISTER_TYPE,(yyvsp[-2].reg)), new Argument(REGISTER_TYPE,(yyvsp[0].reg)));
  }
#line 1907 "./src/parser.cpp"
    break;

  case 48:
#line 261 "Parser.y"
                               {
    (yyval.instruction) = new Instruction(SHL_TYPE, new Argument(REGISTER_TYPE,(yyvsp[-2].reg)), new Argument(REGISTER_TYPE,(yyvsp[0].reg)));
  }
#line 1915 "./src/parser.cpp"
    break;

  case 49:
#line 264 "Parser.y"
                               {
    (yyval.instruction) = new Instruction(SHR_TYPE, new Argument(REGISTER_TYPE,(yyvsp[-2].reg)), new Argument(REGISTER_TYPE,(yyvsp[0].reg)));
  }
#line 1923 "./src/parser.cpp"
    break;

  case 50:
#line 267 "Parser.y"
                    {
    (yyval.instruction) = new Instruction(CALL_TYPE, (yyvsp[0].jumpOperand));
  }
#line 1931 "./src/parser.cpp"
    break;

  case 51:
#line 270 "Parser.y"
                   {
    (yyval.instruction) = new Instruction(JMP_TYPE, (yyvsp[0].jumpOperand));
  }
#line 1939 "./src/parser.cpp"
    break;

  case 52:
#line 273 "Parser.y"
                   {
    (yyval.instruction) = new Instruction(JEQ_TYPE, (yyvsp[0].jumpOperand));
  }
#line 1947 "./src/parser.cpp"
    break;

  case 53:
#line 276 "Parser.y"
                   {
    (yyval.instruction) = new Instruction(JNE_TYPE, (yyvsp[0].jumpOperand));
  }
#line 1955 "./src/parser.cpp"
    break;

  case 54:
#line 279 "Parser.y"
                   {
    (yyval.instruction) = new Instruction(JGT_TYPE, (yyvsp[0].jumpOperand));
  }
#line 1963 "./src/parser.cpp"
    break;

  case 55:
#line 282 "Parser.y"
                                  {
    (yyval.instruction) = new Instruction(LDR_TYPE, new Argument(REGISTER_TYPE,(yyvsp[-2].reg)),(yyvsp[0].dataOperand));
  }
#line 1971 "./src/parser.cpp"
    break;

  case 56:
#line 285 "Parser.y"
                                  {
    (yyval.instruction) = new Instruction(STR_TYPE, new Argument(REGISTER_TYPE,(yyvsp[-2].reg)),(yyvsp[0].dataOperand));
  }
#line 1979 "./src/parser.cpp"
    break;

  case 57:
#line 291 "Parser.y"
               {
    (yyval.dataOperand) = new Argument(DATA_OPERAND_LIT,(yyvsp[0].number));
  }
#line 1987 "./src/parser.cpp"
    break;

  case 58:
#line 294 "Parser.y"
                 {
    (yyval.dataOperand) = new Argument(DATA_OPERAND_SYM,(yyvsp[0].symbol));
  }
#line 1995 "./src/parser.cpp"
    break;

  case 59:
#line 297 "Parser.y"
          {
    (yyval.dataOperand) = new Argument(DATA_OPERAND_MEMLIT,(yyvsp[0].number));
  }
#line 2003 "./src/parser.cpp"
    break;

  case 60:
#line 300 "Parser.y"
          {
    (yyval.dataOperand) = new Argument(DATA_OPERAND_MEMSYMABS,(yyvsp[0].symbol));
  }
#line 2011 "./src/parser.cpp"
    break;

  case 61:
#line 303 "Parser.y"
              {
    (yyval.dataOperand) = new Argument(DATA_OPERAND_MEMSYMPCREL,(yyvsp[0].symbol));
  }
#line 2019 "./src/parser.cpp"
    break;

  case 62:
#line 306 "Parser.y"
            {
    (yyval.dataOperand) = new Argument(DATA_OPERAND_REG,(yyvsp[0].reg));
  }
#line 2027 "./src/parser.cpp"
    break;

  case 63:
#line 309 "Parser.y"
                              {
    (yyval.dataOperand) = new Argument(DATA_OPERAND_REGMEM,(yyvsp[-1].reg));
  }
#line 2035 "./src/parser.cpp"
    break;

  case 64:
#line 312 "Parser.y"
                                          {
    (yyval.dataOperand) = new Argument(DATA_OPERAND_REGMEMLIT,(yyvsp[-3].reg),(yyvsp[-1].number));
  }
#line 2043 "./src/parser.cpp"
    break;

  case 65:
#line 315 "Parser.y"
                                          {
    (yyval.dataOperand) = new Argument(DATA_OPERAND_REGMEMSYM,(yyvsp[-3].reg),(yyvsp[-1].symbol));
  }
#line 2051 "./src/parser.cpp"
    break;

  case 66:
#line 321 "Parser.y"
        {
    (yyval.jumpOperand) = new Argument(JMP_OPERAND_LIT,(yyvsp[0].number));
  }
#line 2059 "./src/parser.cpp"
    break;

  case 67:
#line 324 "Parser.y"
          {
    (yyval.jumpOperand) = new Argument(JMP_OPERAND_SYM,(yyvsp[0].symbol));
  }
#line 2067 "./src/parser.cpp"
    break;

  case 68:
#line 327 "Parser.y"
              {
    (yyval.jumpOperand) = new Argument(JMP_OPERAND_SYMPCREL,(yyvsp[0].symbol));
  }
#line 2075 "./src/parser.cpp"
    break;

  case 69:
#line 330 "Parser.y"
               {
    (yyval.jumpOperand) = new Argument(JMP_OPERAND_MEMLIT,(yyvsp[0].number));
  }
#line 2083 "./src/parser.cpp"
    break;

  case 70:
#line 333 "Parser.y"
               {
    (yyval.jumpOperand) = new Argument(JMP_OPERAND_MEMSYM,(yyvsp[0].symbol));
  }
#line 2091 "./src/parser.cpp"
    break;

  case 71:
#line 336 "Parser.y"
                 {
    (yyval.jumpOperand) = new Argument(JMP_OPERAND_REG,(yyvsp[0].reg));
  }
#line 2099 "./src/parser.cpp"
    break;

  case 72:
#line 339 "Parser.y"
                                   {
    (yyval.jumpOperand) = new Argument(JMP_OPERAND_REGMEM,(yyvsp[-1].reg));
  }
#line 2107 "./src/parser.cpp"
    break;

  case 73:
#line 342 "Parser.y"
                                               {
    (yyval.jumpOperand) = new Argument(JMP_OPERAND_REGMEMLIT,(yyvsp[-3].reg),(yyvsp[-1].number));
  }
#line 2115 "./src/parser.cpp"
    break;

  case 74:
#line 345 "Parser.y"
                                               {
    (yyval.jumpOperand) = new Argument(JMP_OPERAND_REGMEMSYM,(yyvsp[-3].reg),(yyvsp[-1].symbol));
  }
#line 2123 "./src/parser.cpp"
    break;


#line 2127 "./src/parser.cpp"

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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
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
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 349 "Parser.y"
