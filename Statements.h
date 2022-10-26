//
// Created by Jaehyeok Lee on 10/25/2022.
//

#ifndef STEP1_STATEMENTS_H
#define STEP1_STATEMENTS_H

#include <string>

class Statements {
private:
    std::string var_St;
    int length_St;
    std::string label_St;
public:
    Statements();
    Statements(std::string _string);
    static void processStmt(std::string val);

    static void start();
    static void end();
    static void exit();
    static void declscal(std::string val);
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
};
#endif //STEP1_STATEMENTS_H
