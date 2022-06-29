%{
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
%}

%code requires{
   #include "../inc/Types.h"
  #include "../inc/Directive.hpp"
  #include "../inc/Argument.hpp"
  #include "../inc/Instruction.hpp"
  #include "../inc/Line.hpp"
  #include "../inc/Label.hpp"
  #include "../inc/Lines.hpp"

  extern Lines* lineVec;  
}

%output "./src/parser.cpp"
%defines "./inc/parser.hpp"

%union {
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

}
%token<reg>         REGISTER
%token<symbol>      SYMBOL
%token<number>      NUMBER
%token<token>       GLOBAL EXTERN SECTION WORD SKIP ASCII EQU END
%token<token>       HALT INT RET IRET CALL
%token<token>       JMP JEQ JNE JGT
%token<token>       PUSH POP
%token<token>       XCHG ADD SUB MUL DIV CMP NOT AND OR XOR TEST SHL SHR LDR STR
/*
  LEXSYMBOLS
*/
%token<token>       IP PSW SP
%token<token>       COMMENT
%token<token>       COMMA DOT COLON PLUS MINUS STAR MOD DOLLAR LBRACKET RBRACKET NEW_LINE

%type<directive> directive
%type<instruction> instruction
%type<line> line
/* %type<argument> argument */
%type<label> label
%type<lines> lines
%type<symbolList> symbolList
%type<symbolLiterallList> symbolLiterallList
%type<jumpOperand> jumpOperand
%type<dataOperand> dataOperand

%start program

%%
program:
  lines{
    lineVec = $1;
  }
  ;
lines:
  line{
    $$ = new Lines();
    if($1 != nullptr)
      $$->putLine($1);
  }
  | lines line{
    if($2 != nullptr)
      $1->putLine($2);
  }
  ;
line:
  NEW_LINE{
    $$ = nullptr;
  }
  | COMMENT NEW_LINE{
    $$ = nullptr;
    lineNumber++;
  }
  | label NEW_LINE{
    $$ = new Line($1);
    $$->setLineNumber(lineNumber);
    lineNumber++;
  }
  | label directive NEW_LINE{
    $$ = new Line($1, $2);
    $$->setLineNumber(lineNumber);
    lineNumber++;
  } 
  | label instruction NEW_LINE{
    $$ = new Line($1, $2);
    $$->setLineNumber(lineNumber);
    lineNumber++;
  } 
  | label COMMENT NEW_LINE{
    $$ = new Line($1);
    $$->setLineNumber(lineNumber);
    lineNumber++;
  }
  | label directive COMMENT NEW_LINE{
    $$ = new Line($1,$2);
    $$->setLineNumber(lineNumber);
    lineNumber++;
  }
  | label instruction COMMENT NEW_LINE{
    $$ = new Line($1,$2);
    $$->setLineNumber(lineNumber);
    lineNumber++;
  }
  | instruction NEW_LINE{
    $$ = new Line($1);
    $$->setLineNumber(lineNumber);
    lineNumber++;
  }
  | directive NEW_LINE{
    $$ = new Line($1);
    $$->setLineNumber(lineNumber);
    lineNumber++;
  }
  | instruction COMMENT NEW_LINE{
    $$ = new Line($1);
    $$->setLineNumber(lineNumber);
    lineNumber++;
  }
  | directive COMMENT NEW_LINE{
    $$ = new Line($1);
    $$->setLineNumber(lineNumber);
    lineNumber++;
  }
  ;
label:
  SYMBOL COLON{
    $$ = new Label($1);
  }
  ;
directive:
  GLOBAL symbolList{
    $$ = new Directive(GLOBAL_TYPE,$2);
  }
  | EXTERN symbolList{
    $$ = new Directive(EXTERN_TYPE,$2);
  }
  | SECTION DOT SYMBOL{
    $$ = new Directive(SECTION_TYPE,$3);
  }
  | WORD symbolLiterallList{
    $$ = new Directive(WORD_TYPE,$2);
  }
  | SKIP NUMBER{
    $$ = new Directive(SKIP_TYPE,$2);
  }
  | END{
    $$ = new Directive(END_TYPE);
  }
  ;
symbolList:
  SYMBOL{
    $$ = new std::vector<SymbolListElement*>();
    $$->push_back(new SymbolListElement(SYMBOL_TYPE,$1));
  }
  | symbolList COMMA SYMBOL{
    $1->push_back(new SymbolListElement(SYMBOL_TYPE,$3));
  }
  ;
symbolLiterallList:
  SYMBOL{
    $$ = new std::vector<SymbolListElement*>();
    $$->push_back(new SymbolListElement(SYMBOL_TYPE,$1));
  }
  | NUMBER{
    $$ = new std::vector<SymbolListElement*>();
    $$->push_back(new SymbolListElement(LITERAL_TYPE,$1));
  }
  | symbolLiterallList COMMA SYMBOL{
    $1->push_back(new SymbolListElement(SYMBOL_TYPE,$3));
  }
  | symbolLiterallList COMMA NUMBER{
    $1->push_back(new SymbolListElement(LITERAL_TYPE,$3));
  }
  ;
instruction:
  HALT{
    $$ = new Instruction(HALT_TYPE);
  }
  | IRET{
    $$ = new Instruction(IRET_TYPE);
  }
  | RET{
    $$ = new Instruction(RET_TYPE);
  } 
  | INT REGISTER{
    $$ = new Instruction(INT_TYPE, new Argument(REGISTER_TYPE,$2));
  }
  | PUSH REGISTER{
    $$ = new Instruction(PUSH_TYPE, new Argument(REGISTER_TYPE,$2),new Argument(DATA_OPERAND_REGMEM,6));
  }
  | POP REGISTER{
    $$ = new Instruction(POP_TYPE, new Argument(REGISTER_TYPE,$2),new Argument(DATA_OPERAND_REGMEM,6));
  }
  | XCHG REGISTER COMMA REGISTER{
    $$ = new Instruction(XCHG_TYPE, new Argument(REGISTER_TYPE,$2), new Argument(REGISTER_TYPE,$4));
  }
  | ADD REGISTER COMMA REGISTER{
    $$ = new Instruction(ADD_TYPE, new Argument(REGISTER_TYPE,$2), new Argument(REGISTER_TYPE,$4));
  }
  | SUB REGISTER COMMA REGISTER{
    $$ = new Instruction(SUB_TYPE, new Argument(REGISTER_TYPE,$2), new Argument(REGISTER_TYPE,$4));
  }
  | MUL REGISTER COMMA REGISTER{
    $$ = new Instruction(MUL_TYPE, new Argument(REGISTER_TYPE,$2), new Argument(REGISTER_TYPE,$4));
  }
  | DIV REGISTER COMMA REGISTER{
    $$ = new Instruction(DIV_TYPE, new Argument(REGISTER_TYPE,$2), new Argument(REGISTER_TYPE,$4));
  }
  | CMP REGISTER COMMA REGISTER{
    $$ = new Instruction(CMP_TYPE, new Argument(REGISTER_TYPE,$2), new Argument(REGISTER_TYPE,$4));
  }
  | NOT REGISTER{
    $$ = new Instruction(NOT_TYPE, new Argument(REGISTER_TYPE,$2));
  }
  | AND REGISTER COMMA REGISTER{
    $$ = new Instruction(AND_TYPE, new Argument(REGISTER_TYPE,$2), new Argument(REGISTER_TYPE,$4));
  }
  | OR REGISTER COMMA REGISTER{
    $$ = new Instruction(OR_TYPE, new Argument(REGISTER_TYPE,$2), new Argument(REGISTER_TYPE,$4));
  }
  | XOR REGISTER COMMA REGISTER{
    $$ = new Instruction(XOR_TYPE, new Argument(REGISTER_TYPE,$2), new Argument(REGISTER_TYPE,$4));
  }
  | TEST REGISTER COMMA REGISTER{
    $$ = new Instruction(TEST_TYPE, new Argument(REGISTER_TYPE,$2), new Argument(REGISTER_TYPE,$4));
  }
  | SHL REGISTER COMMA REGISTER{
    $$ = new Instruction(SHL_TYPE, new Argument(REGISTER_TYPE,$2), new Argument(REGISTER_TYPE,$4));
  }
  | SHR REGISTER COMMA REGISTER{
    $$ = new Instruction(SHR_TYPE, new Argument(REGISTER_TYPE,$2), new Argument(REGISTER_TYPE,$4));
  }
  | CALL jumpOperand{
    $$ = new Instruction(CALL_TYPE, $2);
  }
  | JMP jumpOperand{
    $$ = new Instruction(JMP_TYPE, $2);
  }
  | JEQ jumpOperand{
    $$ = new Instruction(JEQ_TYPE, $2);
  }
  | JNE jumpOperand{
    $$ = new Instruction(JNE_TYPE, $2);
  }
  | JGT jumpOperand{
    $$ = new Instruction(JGT_TYPE, $2);
  }
  | LDR REGISTER COMMA dataOperand{
    $$ = new Instruction(LDR_TYPE, new Argument(REGISTER_TYPE,$2),$4);
  } 
  | STR REGISTER COMMA dataOperand{
    $$ = new Instruction(STR_TYPE, new Argument(REGISTER_TYPE,$2),$4);
  }
  ;

dataOperand:
  DOLLAR NUMBER{
    $$ = new Argument(DATA_OPERAND_LIT,$2);
  }
  | DOLLAR SYMBOL{
    $$ = new Argument(DATA_OPERAND_SYM,$2);
  }
  | NUMBER{
    $$ = new Argument(DATA_OPERAND_MEMLIT,$1);
  }
  | SYMBOL{
    $$ = new Argument(DATA_OPERAND_MEMSYMABS,$1);
  }
  | MOD SYMBOL{
    $$ = new Argument(DATA_OPERAND_MEMSYMPCREL,$2);
  }
  | REGISTER{
    $$ = new Argument(DATA_OPERAND_REG,$1);
  }
  | LBRACKET REGISTER RBRACKET{
    $$ = new Argument(DATA_OPERAND_REGMEM,$2);
  }
  | LBRACKET REGISTER PLUS NUMBER RBRACKET{
    $$ = new Argument(DATA_OPERAND_REGMEMLIT,$2,$4);
  }
  | LBRACKET REGISTER PLUS SYMBOL RBRACKET{
    $$ = new Argument(DATA_OPERAND_REGMEMSYM,$2,$4);
  }
  ;

jumpOperand:
  NUMBER{
    $$ = new Argument(JMP_OPERAND_LIT,$1);
  }
  | SYMBOL{
    $$ = new Argument(JMP_OPERAND_SYM,$1);
  }
  | MOD SYMBOL{
    $$ = new Argument(JMP_OPERAND_SYMPCREL,$2);
  }
  | STAR NUMBER{
    $$ = new Argument(JMP_OPERAND_MEMLIT,$2);
  }
  | STAR SYMBOL{
    $$ = new Argument(JMP_OPERAND_MEMSYM,$2);
  }
  | STAR REGISTER{
    $$ = new Argument(JMP_OPERAND_REG,$2);
  }
  | STAR LBRACKET REGISTER RBRACKET{
    $$ = new Argument(JMP_OPERAND_REGMEM,$3);
  }
  | STAR LBRACKET REGISTER PLUS NUMBER RBRACKET{
    $$ = new Argument(JMP_OPERAND_REGMEMLIT,$3,$5);
  }
  | STAR LBRACKET REGISTER PLUS SYMBOL RBRACKET{
    $$ = new Argument(JMP_OPERAND_REGMEMSYM,$3,$5);
  }
  ;
%%