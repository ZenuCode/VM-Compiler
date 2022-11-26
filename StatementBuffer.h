#ifndef STEP1_STATEMENTBUFFER_H
#define STEP1_STATEMENTBUFFER_H

#include <string>
#include <map>
#include <iostream>
#include <vector>

class StatementBuffer {
public:
    int count = 0;
    std::map<int, std::pair<std::pair<std::string , int>, std::string>> Instructions; //count op length
    std::map<int, std::string> tempLabel;
    int labelCount = 0;

    void oneInput(StatementBuffer *Instructions);
    void twoInput(StatementBuffer *Instructions, std::string _op);
    void threeInput(StatementBuffer *Instructions, std::string, int);
    void fourInput(StatementBuffer *Instructions, std::string, int, std::string);

private:
    std::string _op;
};

#endif //STEP1_STATEMENTBUFFER_H
