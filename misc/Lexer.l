%{
  #include <stdio.h>
  #include <string.h>
  #include <stdlib.h>
  #include "parser.h"
  /*
    REGISTER DEFINITION
  */
  #define STORE_PC yyval.cur_reg = 7
  #define STORE_SP yyval.cur_reg = 6
  #define STORE_SP yyval.cur_reg = 8
  #define STORE_REG yyval.cur_reg = std::strtol(yytext + 1, 0, 16)

  /*
    HELPERS
  */
  #define STORE_SYMBOL yyval.symbol = new string(yytext, yyleng);
  #define STORE_DEC yyval.number = std::strtol(yytext, 0, 10)
  #define STORE_HEX yyval.number = std::strtol(yytext, 0, 16)
%}
%option outfile="lexer.c" header-file="lexer.h"
%option noyywrap
%%
  /*
    INSTRUCTIONS AND DIRECTIVES
  */
  ".global"               return GLOBAL;
  ".extern"               return EXTERN;
  ".section"              return SECTION;
  ".word"                 return WORD;
  ".skip"                 return SKIP;
  ".ascii"                return ASCII;
  ".equ"                  return EQU;
  ".end"                  return END;
  "halt"                  return HALT;
  "int"                   return INT;
  "iret"                  return IRET;
  "call"                  return CALL;
  "ret"                   return RET;
  "jmp"                   return JMP;
  "jeq"                   return JEQ;
  "jne"                   return JNE;
  "jgt"                   return JGT;
  "push"                  return PUSH;
  "pop"                   return POP;
  "xchg"                  return XCHG;
  "add"                   return ADD;
  "sub"                   return SUB;
  "mul"                   return MUL;
  "div"                   return DIV;
  "cmp"                   return CMP;
  "not"                   return NOT;
  "and"                   return AND;
  "or"                    return OR;
  "xor"                   return XOR;
  "test"                  return TEST;
  "shl"                   return SHL;
  "shr"                   return SHR;
  "ldr"                   return LDR;
  "str"                   return STR;
  /*
    REGISTERS
  */
  "pc"                    return PC;
  "psw"                   return PSW;
  "sp"                    return SP;
  /*
    MISC
  */
  #.*                     return COMMENT;
  r[0-7]                  STORE_REG; return REGISTER;
  0x[0-9A-Fa-f]+          STORE_HEX; return NUMBER;
  [0-9]+                  STORE_DEC; return NUMBER;
  [a-zA-z_][a-zA-Z0-9_]*  STORE_SYMBOL; return SYMBOL;
  /*
    LEXSYMBOLS
  */
  ","                     return COMMA;
  ":"                     return COLON;
  "+"                     return PLUS;
  "-"                     return MINUS;
  "*"                     return STAR;
  "%"                     return MOD;
  "$"                     return DOLLAR;
  "#"                     return HASH;
  "["                     return LBRACKET;
  "]"                     return RBRACKET;
  "\n"                    return NEW_LINE;
  [ \t]+                  ;
%%
