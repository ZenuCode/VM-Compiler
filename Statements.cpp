#include <string>
#include <regex>
#include "Statements.h"
#include "SymbolTable.h"

Statements::Statements() {}

Statements::Statements(std::string input)  {
    var_St = input;
}

void Statements::processStmt(std::string input) {
    std::string temp = std::to_string(input.back());
    std::cout << temp << std::endl;
    input.pop_back();
    input.pop_back();
    if(input == "declscal") {
        declscal(temp);
    }
}

void start() {

}

void end() {

}

void exit() {

}

void Statements::declscal(std::string var) {
    SymbolTable temp;
    std::cout << var << std::endl;
    temp.addMap(var);
}
/*
void declarr(std::string, int);
void label(std::string);
void gosublabel(std::string);
void start();
void end();
void exit();
void jump(std::string);
void jumpzero(std::string);
void jumpnzero(std::string);
void gosub(std::string);
void return();
void pushscal(std::string);
void pusharr(std::string);
void pushi(int);
void pop();
void popscal(std::string);
void poparr(std::string);
void dup();
void swap();
void add();
void negate();
void mul();
void div();
void printtos();
void prints();
 */
