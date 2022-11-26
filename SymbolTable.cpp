//
// Created by Jaehyeok Lee on 10/25/2022.
//

#include <map>
#include <string>
#include "SymbolTable.h"

SymbolTable::SymbolTable( ) {}

void SymbolTable::input(SymbolTable *orig, std::string name, int idx, int length) {
    if(subRouON > 0) {
        subMem[subRouON] += length;
    }

    /*
    if(idx == -1) {
        for (int i = 0; i != length; i++) {
            for (int j = 0; j < 20; j++) {
                if (indexes.count(orig->index) == 1) {
                    orig->index + 1;
                } else {
                    indexes[orig->index] = i;
                    orig->Symbols[name] = std::make_pair( orig->index, length);
                    orig->index = orig->index + 1;
                }
            }
        }
    }
     */

    if(idx != 0) {
        for(int i = 0; i != idx; i++) {
            if(indexes.count(orig->index)) {
                orig->index++;
                i--;
            } else {
                indexes[i] = length;
                orig->Symbols[name] = std::make_pair( orig->index, 1);
                orig->index++;
            }
        }
        //indexes[idx] = length;
        //orig->Symbols[name] = std::make_pair( idx, length);
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


