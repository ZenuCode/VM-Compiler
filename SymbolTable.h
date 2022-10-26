
#ifndef SYMBOL_H
#define SYMBOL_H

#include <iostream>
#include <map>

class SymbolTable {
private:
    std::map<std::string, std::pair<int, int>> totalMap;
    int idx;
public:
    SymbolTable();
    void addMap(std::string);
};

#endif //SYMBOL_H
