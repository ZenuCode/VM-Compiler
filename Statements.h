
#ifndef STEP1_STATEMENTS_H
#define STEP1_STATEMENTS_H

#include <string>
#include "SymbolTable.h"
#include "StatementBuffer.h"

class Statements {
private:
    std::string key;
    std::string length;
public:
    Statements();
    void processStmt(std::string, StatementBuffer *Instructions, SymbolTable *Symbols);
    void processPrint(StatementBuffer Instructions,  SymbolTable Symbols);

    void declscal(SymbolTable *, std::string);
    void declarr(SymbolTable *, std::string, std::string);
    void label(SymbolTable *, std::string, int);
    void gosublabel(StatementBuffer *, SymbolTable *Symbols, std::string, int);
    void start(StatementBuffer *);
    void end(StatementBuffer *);
    void exit(StatementBuffer *);
    void jump(StatementBuffer *);
    void jumpzero(StatementBuffer *, std::string);
    void jumpnzero(StatementBuffer *, std::string);
    void gosub(StatementBuffer *, SymbolTable*, std::string, int);
    void returnF(StatementBuffer *);
    void pushscal(StatementBuffer *, std::string);
    void pusharr(StatementBuffer *, std::string);
    void pushi(StatementBuffer *, std::string);
    void pop(StatementBuffer *);
    void popscal(StatementBuffer *, std::string);
    void poparr(StatementBuffer *, std::string);
    void dup(StatementBuffer *);
    void swapF(StatementBuffer *);
    void add(StatementBuffer *);
    void negate(StatementBuffer *);
    void mul(StatementBuffer *);
    void div(StatementBuffer *);
    void printtos(StatementBuffer *);
    void prints(StatementBuffer *, SymbolTable *, std::string);
};
#endif //STEP1_STATEMENTS_H
