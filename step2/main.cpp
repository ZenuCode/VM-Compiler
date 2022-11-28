#include <iostream>
#include <fstream>
#include "Memory.h"

int main(int argc, char *argv[]) {
    std::ifstream binaryFile(argv[1]);

    if (!binaryFile.is_open( )) {
        std::cout << "failed to open file " << argv[1] << ", terminating" << std::endl;
        return -1;
    }

    Memory VM;

    std::string line;
    while(binaryFile.peek() != EOF) {
        std::getline(binaryFile, line);
        VM.takeInputs(&VM, line);
    }

    VM.processStmt(&VM);

    return 0;
}