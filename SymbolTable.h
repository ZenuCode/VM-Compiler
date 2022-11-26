
#ifndef SYMBOL_H
#define SYMBOL_H

#include <iostream>
#include <map>
#include <vector>

class SymbolTable {
public:
    std::map<std::string, std::pair<int, int>> Symbols; //Char, Mem, Mem
    std::map<int, int> indexes;
    //std::map<std::string, std::pair<int, int>> subroutine;
    std::map<std::string, std::pair<int, int>> * subroutine = new std::map<std::string, std::pair<int, int>>[20];
    int index = 0;
    int subRouON = 0;
    int subMem[20];

    SymbolTable();
    void input(SymbolTable *orig, std::string name, int idx, int length);
};

#endif //SYMBOL_H
