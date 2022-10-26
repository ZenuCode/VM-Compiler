#include <iostream>
#include <fstream>
#include "Statements.h"
#include "SymbolTable.h"

int main(int argc, char *argv[]) {
    std::ifstream binaryFile(argv[1]);

    if (!binaryFile.is_open( )) {
        std::cout << "failed to open file " << argv[1] << ", terminating" << std::endl;
        return -1;
    } else {
        std::cout << "right" << std::endl;
    }

    std::string line;
    while(std::getline(binaryFile, line)) {
       Statements::processStmt(line);
    }

    return 0;
}
