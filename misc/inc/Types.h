#pragma once

enum ArgumentTypes {
  REGISTER_TYPE,
  /*
    DATA OPERANDS
  */
  DATA_OPERAND_LIT, 
  DATA_OPERAND_SYM,
  DATA_OPERAND_MEMLIT,
  DATA_OPERAND_MEMSYMABS,
  DATA_OPERAND_MEMSYMPCREL,
  DATA_OPERAND_REG,
  DATA_OPERAND_REGMEM,
  DATA_OPERAND_REGMEMLIT,
  DATA_OPERAND_REGMEMSYM,
  /*
    JUMP OPERANDS
  */
  JMP_OPERAND_LIT,
  JMP_OPERAND_SYM,
  JMP_OPERAND_SYMPCREL,
  JMP_OPERAND_MEMLIT,
  JMP_OPERAND_MEMSYM,
  JMP_OPERAND_REG,
  JMP_OPERAND_REGMEM,
  JMP_OPERAND_REGMEMLIT,
  JMP_OPERAND_REGMEMSYM,
};

enum InstructionTypes {
  HALT_TYPE,
  INT_TYPE,
  IRET_TYPE,
  CALL_TYPE,
  RET_TYPE,
  JMP_TYPE,
  JEQ_TYPE,
  JNE_TYPE,
  JGT_TYPE,
  PUSH_TYPE,
  POP_TYPE,
  XCHG_TYPE,
  ADD_TYPE,
  SUB_TYPE,
  MUL_TYPE,
  DIV_TYPE,
  CMP_TYPE,
  NOT_TYPE,
  AND_TYPE,
  OR_TYPE,
  XOR_TYPE,
  TEST_TYPE,
  SHL_TYPE,
  SHR_TYPE,
  LDR_TYPE,
  STR_TYPE,
};
enum DirectiveType {
  GLOBAL_TYPE,
  EXTERN_TYPE,
  SECTION_TYPE,
  WORD_TYPE,
  SKIP_TYPE,
  EQU_TYPE,
  END_TYPE,
};

enum SymbolListElementType {
  SYMBOL_TYPE,
  LITERAL_TYPE,
};

enum SymbolTableEntryType {
  NOTYP,
  SCTN,
};

enum Binding{
  LOC,
  GLOB,
};
