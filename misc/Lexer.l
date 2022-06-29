%{
  #include <stdio.h>
  #include <string.h>
  #include <stdlib.h>
  #include "../inc/parser.hpp"
  /*
    REGISTER DEFINITION
  */
  #define STORE_PC yylval.reg = 7
  #define STORE_SP yylval.reg = 6
  #define STORE_PSW yylval.reg = 8
  #define STORE_REG yylval.reg = std::strtol(yytext + 1, 0, 16)

  /*
    HELPERS
  */
  #define STORE_SYMBOL yylval.symbol = new std::string(yytext, yyleng);
  #define STORE_DEC yylval.number = std::strtol(yytext, 0, 10)
  #define STORE_HEX yylval.number = std::strtol(yytext + 2, 0, 16)
%}
%option outfile="./src/lexer.cpp" header-file="./inc/lexer.hpp"
%option noyywrap
%%
".global"               {return GLOBAL;}
".extern"               {return EXTERN;}
".section"              {return SECTION;}
".word"                 {return WORD;}
".skip"                 {return SKIP;}
".ascii"                {return ASCII;}
".equ"                  {return EQU;}
".end"                  {return END;}
"halt"                  {return HALT;}
"int"                   {return INT;}
"iret"                  {return IRET;}
"call"                  {return CALL;}
"ret"                   {return RET;}
"jmp"                   {return JMP;}
"jeq"                   {return JEQ;}
"jne"                   {return JNE;}
"jgt"                   {return JGT;}
"push"                  {return PUSH;}
"pop"                   {return POP;}
"xchg"                  {return XCHG;}
"add"                   {return ADD;}
"sub"                   {return SUB;}
"mul"                   {return MUL;}
"div"                   {return DIV;}
"cmp"                   {return CMP;}
"not"                   {return NOT;}
"and"                   {return AND;}
"or"                    {return OR;}
"xor"                   {return XOR;}
"test"                  {return TEST;}
"shl"                   {return SHL;}
"shr"                   {return SHR;}
"ldr"                   {return LDR;}
"str"                   {return STR;}
"pc"                    {return IP;}
"psw"                   {return PSW;}
"sp"                    {return SP;}
#.*                     {return COMMENT;}
r[0-7]                  {STORE_REG; return REGISTER;}
0x[0-9A-Fa-f]+          {STORE_HEX; return NUMBER;}
[0-9]+                  {STORE_DEC; return NUMBER;}
[a-zA-Z_][a-zA-Z0-9_]*  {STORE_SYMBOL; return SYMBOL;}
","                     {return COMMA;}
"."                     {return DOT;}
":"                     {return COLON;}
"+"                     {return PLUS;}
"-"                     {return MINUS;}
"*"                     {return STAR;}
"%"                     {return MOD;}
"$"                     {return DOLLAR;}
"["                     {return LBRACKET;}
"]"                     {return RBRACKET;}
"\n"                    {return NEW_LINE;}
[ \t]+                  {;}
%%