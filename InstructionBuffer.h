//
// Created by Jaehyeok Lee on 10/25/2022.
//
#ifndef STEP1_INSTRUCTIONBUFFER_H
#define STEP1_INSTRUCTIONBUFFER_H

#include <string>
#include <map>
#include <iostream>

class InstructionBuffer {
public:
    std::string op;
    int num;
    int count = 0;

    InstructionBuffer();
    InstructionBuffer(std::string _op, int _num);
};

#endif //STEP1_INSTRUCTIONBUFFER_H
