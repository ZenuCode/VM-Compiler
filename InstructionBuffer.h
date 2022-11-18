#ifndef STEP1_STATEMENTBUFFER_H
#define STEP1_STATEMENTBUFFER_H

#include <string>
#include <map>
#include <iostream>
#include <vector>

class StatementBuffer {
public:
    int count = 0;
    std::map<int, std::pair<std::string , int>> Instructions;

    void oneInput(StatementBuffer *Instructions);
    void twoInput(StatementBuffer *Instructions, std::string _op);
    void threeInput(StatementBuffer *Instructions, std::string, int);

private:
    std::string _op;
};

#endif //STEP1_STATEMENTBUFFER_H
