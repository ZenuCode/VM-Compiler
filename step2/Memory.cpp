#include <sstream>
#include <iostream>
#include "Memory.h"

void Memory::takeInputs(Memory *VM, std::string input) {
    std::istringstream ss(input);
    std::string op;
    int num = -10;
    ss >> op;
    ss >> num;
    if(num == -10) {
        addBuffer(VM, op);
        return;
    } else {
        VM->Instructions[VM->InstructionCount] = std::make_pair(op, num);
        VM->InstructionCount++;
    }
}

void Memory::processStmt(Memory *VM) {
    std::string op;
    int num = 0;
    int index = 0;

    while(op != "OP_EXIT_PROGRAM" ){
        op = VM->Instructions[index].first;
        num = VM->Instructions[index].second;

        if (op == "OP_JUMP") {
            index = num - 1;
        } else if (op == "OP_JUMPZERO") {
            int check = VM->stack[VM->stackSub][VM->stackCount - 1];
            if(check == 0) {
                index = num - 1;
            }
            VM->stack[VM->stackSub].erase(VM->stackCount - 1);
            VM->stackCount--;

        } else if (op == "OP_JUMPNZERO") {
            int check = VM->stack[VM->stackSub][VM->stackCount - 1];
            if(check != 0) {
                index = num - 1;
            }
            VM->stack[VM->stackSub].erase(VM->stackCount - 1);
            VM->stackCount--;

        } else if (op == "OP_GOSUB") {
            VM->returnAddr = index + 1;
            index = VM->Instructions[num].second - 1;
        } else if (op == "OP_RETURN") {
            index = VM->returnAddr - 1;
            VM->dataSub--;
        } else if (op == "OP_ENTER_SUBROUTINE") {
            VM->dataSub++;
        } else if (op == "OP_EXIT_SUBROUTINE") {
            VM->stackSub--;
            VM->dataSub--;
        } else if (op == "OP_START_PROGRAM") {
            //Done
        } else if (op == "OP_EXIT_PROGRAM") {
            //Done
        } else if (op == "OP_PUSHSCALAR") {
            int val = VM->data[VM->dataSub][num].second;
            VM->stack[VM->stackSub][VM->stackCount] = val;
            VM->stackCount++;
        } else if (op == "OP_PUSHARRAY") {
            int valIndex = VM->stack[VM->stackSub][VM->stackCount - 1];
            VM->stack[VM->stackSub].erase(VM->stackCount - 1);
            VM->stackCount--;
            int valData = VM->data[dataSub][valIndex].second;
            //std::cout << "Push Data " << valData << "Index " << valIndex << std::endl;
            VM->stack[VM->stackSub][VM->stackCount] = valData;
            VM->stackCount++;
        } else if (op == "OP_PUSHI") {
            VM->stack[VM->stackSub][VM->stackCount] = num;
            VM->stackCount++;
        } else if (op == "OP_POPSCALAR") {
            VM->data[VM->dataSub][num] = std::make_pair("", VM->stack[VM->stackSub][VM->stackCount - 1]);
            VM->stack[VM->stackSub].erase(VM->stackCount - 1);
            VM->stackCount--;
        } else if (op == "OP_POPARRAY") {
            int valIndex = VM->stack[VM->stackSub][VM->stackCount - 1];
            int valData = VM->stack[VM->stackSub][VM->stackCount - 2];
            VM->stack[VM->stackSub].erase(VM->stackCount - 1);
            VM->stack[VM->stackSub].erase(VM->stackCount - 2);
            VM->stackCount = VM->stackCount - 2;
            VM->data[VM->dataSub][valIndex] = std::make_pair("", valData);
        } else if (op == "OP_POP") {
            VM->stack[VM->stackSub].erase(VM->stackCount);
            VM->stackCount--;
        } else if (op == "OP_DUP") {
            int val = VM->stack[VM->stackSub][VM->stackCount - 1];
            VM->stack[VM->stackSub][VM->stackCount] = val;
            VM->stackCount++;
        } else if (op == "OP_SWAP") {
            int valtop = VM->stack[VM->stackSub][VM->stackCount - 1];
            int valdown = VM->stack[VM->stackSub][VM->stackCount - 2];
            VM->stack[VM->stackSub][VM->stackCount - 2] = valtop;
            VM->stack[VM->stackSub][VM->stackCount - 1] = valdown;
        } else if (op == "OP_ADD") {
            int valtop = VM->stack[VM->stackSub][VM->stackCount - 1];
            int valdown = VM->stack[VM->stackSub][VM->stackCount - 2];
            int valtotal = valtop + valdown;
            VM->stack[VM->stackSub][VM->stackCount - 2] = valtotal;
            VM->stack[VM->stackSub].erase(VM->stackCount - 1);
            VM->stackCount--;
        } else if (op == "OP_NEGATE") {
            int val = VM->stack[VM->stackSub][VM->stackCount - 1];
            VM->stack[VM->stackSub][VM->stackCount - 1] = -1 * val;
        } else if (op == "OP_MUL") {
            int valtop = VM->stack[VM->stackSub][VM->stackCount - 1];
            int valdown = VM->stack[VM->stackSub][VM->stackCount - 2];
            int valtotal = valtop * valdown;
            VM->stack[VM->stackSub][VM->stackCount - 2] = valtotal;
            VM->stack[VM->stackSub].erase(VM->stackCount - 1);
            VM->stackCount--;
        } else if (op == "OP_DIV") {
            int valtop = VM->stack[VM->stackSub][VM->stackCount - 1];
            int valdown = VM->stack[VM->stackSub][VM->stackCount - 2];
            int valtotal = valtop / valdown;
            VM->stack[VM->stackSub][VM->stackCount - 2] = valtotal;
            VM->stack[VM->stackSub].erase(VM->stackCount - 1);
            VM->stackCount--;
        } else if (op == "OP_PRINTS") {
            std::string temp = VM->stringBuffer[num];
            std::cout << temp << std::endl;
        } else if (op == "OP_PRINTTOS") {
            int val = VM->stack[VM->stackSub][VM->stackCount - 1];
            std::cout << val << std::endl;
            VM->stack[VM->stackSub].erase(VM->stackCount - 1);
            VM->stackCount--;
        }
        index++;
    }
    std::cout << "Terminated Normally" << std::endl;
}

void Memory::addBuffer(Memory *VM, std::string sentence) {
    VM->stringBuffer[VM->bufferCount] = sentence;
    VM->bufferCount++;
}

