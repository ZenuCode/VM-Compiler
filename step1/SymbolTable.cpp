
#include <map>
#include <string>
#include "SymbolTable.h"

SymbolTable::SymbolTable( ) {}

void SymbolTable::input(SymbolTable *orig, std::string name, int idx, int length) {
    if(subRouON > 0) {
        subMem[subRouON] += length;
    }

    int trigger = 0;
    if(idx == -1) {
        for(int i = 0; i < length; i++) {
            if (orig->index == 0) {
                indexes[orig->index] = 1; // length
                if(trigger != 1) {
                    orig->Symbols[name] = std::make_pair(orig->index, length);
                }
                orig->index = orig->index + 1;
                trigger = 1;
            } else {
                for (int i = 0; i < 20; i++) {
                    if (indexes.count(orig->index) == 1) {
                        orig->index + 1;
                    } else {
                        break;
                    }
                }
                indexes[orig->index] = 1;
                if(trigger != 1) {
                    orig->Symbols[name] = std::make_pair(orig->index, length);
                }
                orig->index = orig->index + 1;
                trigger = 1;
            }
        }
        return;
    }

    if(idx != 0) {
        indexes[idx] = length;
        orig->Symbols[name] = std::make_pair(idx, length);
        orig->index + 1;
        return;
    }

    if(orig->index == 0) {
        indexes[orig->index] = length;
        orig->Symbols[name] = std::make_pair( orig->index, length);
        orig->index = orig->index + 1;
    } else {
        for(int i = 0 ; i < 20 ; i++) {
            if(indexes.count(orig->index) == 1) {
                orig->index + 1;
            } else {
                break;
            }
        }
        indexes[orig->index] = length;
        orig->Symbols[name] = std::make_pair( orig->index, length);
        orig->index = orig->index + 1;
    }
}


