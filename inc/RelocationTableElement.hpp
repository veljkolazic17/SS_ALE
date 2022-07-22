#pragma once
#include "../misc/inc/Types.h"
#include "./SymbolTableElement.hpp"
#include "./BackpatchElement.hpp"
struct RelocationTableElement{
    int offset;
    int addend;
    RELOCATION_TYPE type;
    SymbolTableElement* symbol;
};