#include <iostream>
#include <fstream>
#include <sstream>
#include "Statements.h"
#include "SymbolTable.h"
#include "InstructionBuffer.h"

int main(int argc, char *argv[]) {
    std::ifstream binaryFile(argv[1]);

    if (!binaryFile.is_open( )) {
        std::cout << "failed to open file " << argv[1] << ", terminating" << std::endl;
        return -1;
    }

    int count = 0;
    std::string line;
    while(binaryFile.peek() != EOF) {
        std::getline(binaryFile, line);
        count++;
    }

    binaryFile.clear();
    binaryFile.seekg(0, std::ios::beg);

    InstructionBuffer* instTable = new InstructionBuffer[count];
    SymbolTable* symTable = new SymbolTable[count];

    int position = 0;
    std::string arr[5];
    while(binaryFile.peek() != EOF) {
        std::getline(binaryFile, line);
        Statements::processStmt(line, arr);
        instTable[position].op = arr[0];
        instTable[position].num = stoi(arr[1]);
        if(arr[3] != "-1" || arr[3] != "-2") {
            symTable[position].name = arr[2];
            if(stoi(arr[3]) > 0) {
                symTable[position].location = symTable[0].index + -1 * stoi(arr[3]);
                symTable[0].index = -1 * stoi(arr[3]);
            } else {
                symTable[position].location = stoi(arr[3]);
            }
            symTable[position].length = stoi(arr[4]);
        }
        position++;
    }

    return 0;
}
