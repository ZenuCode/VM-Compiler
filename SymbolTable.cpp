//
// Created by Jaehyeok Lee on 10/25/2022.
//

#include <map>
#include <string>
#include "SymbolTable.h"

SymbolTable::SymbolTable( ) {
    index = 0;
}

SymbolTable::SymbolTable(std::string _name, int _location, int _length) {
    name = _name;
    location = _location;
    length = _length;
}

void SymbolTable::addMap(std::string var) {
    totalMap.insert(std::make_pair(var, std::make_pair(idx, 1)));
}

