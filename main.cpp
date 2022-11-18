#include <iostream>
#include <fstream>
#include <sstream>
#include "Statements.h"
#include "SymbolTable.h"
#include "StatementBuffer.h"

int main(int argc, char *argv[]) {
    std::ifstream binaryFile(argv[1]);

    if (!binaryFile.is_open( )) {
        std::cout << "failed to open file " << argv[1] << ", terminating" << std::endl;
        return -1;
    }

    std::map<StatementBuffer, SymbolTable> total;
    StatementBuffer Instructions;
    SymbolTable Symbols;

    int count = 0;
    std::string line;
    while(binaryFile.peek() != EOF) {
        std::getline(binaryFile, line);
        count++;
        Statements().processStmt(line, &Instructions, &Symbols);
    }

    Statements().processPrint(Instructions, Symbols);
    return 0;
}
