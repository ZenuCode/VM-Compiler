
#ifndef STEP1_STRINGBUFFER_H
#define STEP1_STRINGBUFFER_H

#include <map>
#include <string>

class StringBuffer {
public:
    int count = 0;
    std::map<int, std::string> stringBuff;

    void insertStr(StringBuffer *, std::string, int);
    std::string getStr(StringBuffer *, int);
};

#endif //STEP1_STRINGBUFFER_H
