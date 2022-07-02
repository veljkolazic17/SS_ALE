#pragma once
#include <asm/types.h>

typedef __u16	SElf16_Addr;
typedef __u8	SElf16_Half;
typedef __u16	SElf16_Off;
typedef __s16	SElf16_Sword;
typedef __u16	SElf16_Word;
typedef __u32   SElf16_Dword;
typedef __u64   Self16_Qword;

//*.*.Magic.*.*
#define MAGIC           5

//DCLASS
#define SELFDATANONE    0
#define SELFDATALSB     1
#define SLEFDATAMSB     2

//TYPE
#define SET_NONE        0
#define SET_REL         1
#define SET_EXEC        2

//SH TYPE
#define SHT_NULL        0           /* Section header table entry unused */
#define SHT_PROGBITS    1           /* Program data */
#define SHT_SYMTAB      2           /* Symbol table */
#define SHT_STRTAB      3           /* String table */
#define SHT_RELA        4           /* Relocation entries with addends */
#define SHT_NOBITS      5           /* Program space with no data (bss) */
#define SHT_REL         6           /* Relocation entries, no addends */

//Symbol table binding
#define STB_LOCAL       0           /* Local symbol */
#define STB_GLOBAL      1           /* Global symbol */

//Symbol table type
#define STT_NOTYPE      0           /* Symbol type is unspecified */
#define STT_SECTION     1           /* Symbol associated with a section */

//Rela types
#define UNDEFINED       1
#define HYPO_16         2
#define HYPO_16S        4
#define HYPO_REL16      8
#define HYPO_PC16       16

#define HEADER_OFFSET   18

typedef struct{
    unsigned char se_ident[MAGIC];  /* SELF "magic number" */
    SElf16_Half se_dclass;          /* Data representation type */
    SElf16_Half se_type;            /* Type of file (always will be REL) */
    SElf16_Addr se_entry;           /* Entry virtual address */
    SElf16_Off se_shoff;            /* Section header table offset */
    SElf16_Off se_shsize;          /* Size of SELF header */
    SElf16_Off se_shentsize;       /* Section header table entry size */
    SElf16_Off se_shnum;           /* Section header table number of entries */
    SElf16_Off se_shstrndx;        /* Section name string table index in section header table*/
}self16_hdr;

typedef struct{
    SElf16_Off sh_name;             /* Offset to name of section in section name string table */
    SElf16_Word sh_type;            /* Type of section */
    SElf16_Addr sh_addr;            /* Addres where section starts */
    SElf16_Off sh_offset;           /* Offset to start of a section in SELF */
    SElf16_Word sh_size;            /* Section size */
    SElf16_Half sh_link;            /* Index of another section in setion header */
    SElf16_Half sh_info;            /* Section specific data */
    SElf16_Half sh_entsize;         /* Section entry length (!=0 for Rela & Sym) */
}self16_shdr;

typedef struct{
    SElf16_Off st_name;             /* Section name string table index */
    SElf16_Half st_binding;         /* Binding */
    SElf16_Half st_type;            /* Type */
    SElf16_Off st_shndx;            /* Index of section in section header table where symbol is located */
    SElf16_Sword st_value;          /* Value of symbol */
    SElf16_Word st_size;            /* Size of symbol only for sections */
}slef16_sym;

typedef struct{
    SElf16_Addr r_offset;           /* Offset where change is needed */
    SElf16_Word r_addend;           /* Addend */
    SElf16_Half r_type;             /* Type */
    SElf16_Off r_symbol;            /* Index in symbol table of symbol */
}self16_rela;