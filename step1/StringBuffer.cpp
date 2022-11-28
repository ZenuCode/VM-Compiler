#include "StringBuffer.h"

void StringBuffer::insertStr(StringBuffer * Strings, std::string val, int position) {
    Strings->stringBuff[position] = val;
    Strings->count++;
}

std::string StringBuffer::getStr(StringBuffer * Strings, int position) {
    return Strings->stringBuff[position];
}
