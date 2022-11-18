
#ifndef SYMBOL_H
#define SYMBOL_H

#include <iostream>
#include <map>

class SymbolTable {
public:
    std::map<std::string, std::pair<int , int>> Symbols;
    int index = 0;

    SymbolTable();
    void input(SymbolTable *orig, std::string name, int idx, int length);
};

#endif //SYMBOL_H
