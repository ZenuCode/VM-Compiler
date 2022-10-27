
#ifndef SYMBOL_H
#define SYMBOL_H

#include <iostream>
#include <map>

class SymbolTable {
private:
    std::map<std::string, std::pair<int, int>> totalMap;
public:
    SymbolTable();
    SymbolTable(std::string _name, int _idx, int _length);
    void addMap(std::string);

    std::string name;
    int location;
    int length;
    int index = 0;
};

#endif //SYMBOL_H
