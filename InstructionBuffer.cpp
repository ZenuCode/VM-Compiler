#include "InstructionBuffer.h"

void StatementBuffer::oneInput(StatementBuffer *orig) {
}

void StatementBuffer::twoInput(StatementBuffer *orig, std::string op){
    orig->Instructions[orig->count] = std::make_pair(op, -1);
    orig->count++;
}

void StatementBuffer::threeInput(StatementBuffer *orig, std::string op, int length) {
    orig->Instructions[orig->count] = std::make_pair(op, length);
    orig->count++;
}

