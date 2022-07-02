/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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

#line 60 "./inc/parser.hpp"

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
    NEW_LINE = 309
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


#line 147 "./inc/parser.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_INC_PARSER_HPP_INCLUDED  */
