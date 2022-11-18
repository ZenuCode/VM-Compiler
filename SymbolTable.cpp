//
// Created by Jaehyeok Lee on 10/25/2022.
//

#include <map>
#include <string>
#include "SymbolTable.h"

SymbolTable::SymbolTable( ) {}

void SymbolTable::input(SymbolTable *orig, std::string name, int idx, int length) {
    orig->Symbols[name] = std::make_pair(orig->index + idx, length);
    orig->index = orig->index + idx + 1;
}


