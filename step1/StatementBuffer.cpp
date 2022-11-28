#include "StatementBuffer.h"

void StatementBuffer::oneInput(StatementBuffer *orig) {}

void StatementBuffer::twoInput(StatementBuffer *orig, std::string op){
    orig->Instructions[orig->count] = std::make_pair(std::make_pair(op, -1), "");
    orig->count++;
}

void StatementBuffer::threeInput(StatementBuffer *orig, std::string op, int length) {
    orig->Instructions[orig->count] = std::make_pair(std::make_pair(op, length), "");
    orig->count++;
}

void StatementBuffer::fourInput(StatementBuffer * orig, std::string op, int num , std::string label) {
    orig->Instructions[orig->count] = std::make_pair(std::make_pair(op, num), label);
    orig->count++;
}

