//
// Created by Jaehyeok Lee on 10/25/2022.
//

#include <map>
#include <string>
#include "SymbolTable.h"

SymbolTable::SymbolTable( ) {
    idx = 0;
}

void SymbolTable::addMap(std::string var) {
    totalMap.insert(std::make_pair(var, std::make_pair(idx, 1)));
    for(auto it = totalMap.cbegin(); it != totalMap.cend(); ++it)
    {
        std::cout << it->first << " " << it->second.first << " " << it->second.second << "\n";
    }
}
