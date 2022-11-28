#ifndef STEP2_MEMORY_H
#define STEP2_MEMORY_H


#include <string>
#include <map>

class Memory {
public:
    std::map<int, std::pair<std::string, int>> Instructions;
    std::map<int, std::string> stringBuffer;
    std::map<int, int> * stack = new std::map<int, int>[20] ;
    std::map<int, std::pair<std::string, int>> * data = new std::map<int, std::pair<std::string, int>>[20];
    int returnAddr;
    int bufferCount = 0;
    int stackSub = 0;
    int stackCount = 0;
    int InstructionCount = 0;
    int dataCount = 0;
    int dataSub = 0;

    void takeInputs(Memory *VM, std::string op);
    void processStmt(Memory *VM);

    void addBuffer(Memory *VM, std::string buffer);
};


#endif //STEP2_MEMORY_H
