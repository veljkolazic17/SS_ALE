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
    STRING = 260,
    NUMBER = 261,
    GLOBAL = 262,
    EXTERN = 263,
    SECTION = 264,
    WORD = 265,
    SKIP = 266,
    ASCII = 267,
    EQU = 268,
    END = 269,
    HALT = 270,
    INT = 271,
    RET = 272,
    IRET = 273,
    CALL = 274,
    JMP = 275,
    JEQ = 276,
    JNE = 277,
    JGT = 278,
    PUSH = 279,
    POP = 280,
    XCHG = 281,
    ADD = 282,
    SUB = 283,
    MUL = 284,
    DIV = 285,
    CMP = 286,
    NOT = 287,
    AND = 288,
    OR = 289,
    XOR = 290,
    TEST = 291,
    SHL = 292,
    SHR = 293,
    LDR = 294,
    STR = 295,
    IP = 296,
    PSW = 297,
    SP = 298,
    COMMENT = 299,
    COMMA = 300,
    DOT = 301,
    COLON = 302,
    PLUS = 303,
    MINUS = 304,
    STAR = 305,
    MOD = 306,
    DOLLAR = 307,
    LBRACKET = 308,
    RBRACKET = 309,
    NEW_LINE = 310
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


#line 148 "./inc/parser.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_INC_PARSER_HPP_INCLUDED  */
