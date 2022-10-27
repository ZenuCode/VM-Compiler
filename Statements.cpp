#include <string>
#include <regex>
#include <cstring>
#include "Statements.h"
#include "SymbolTable.h"
#include "InstructionBuffer.h"

Statements::Statements() {}

Statements::Statements(std::string input)  {
    var_St = input;
}

void Statements::processStmt(std::string input, std::string arr[]) {
    //Process input
    std::istringstream ss(input);
    std::string word;
    std::string array[3]; //Name, Key, Length
    int i = 0;
    while (ss >> word) {
        array[i] = word;
        i++;
    }

    std::string name;
    std::string key;
    std::string length;

    if(array[1] == "") {
        name = array[0];
    } else if (array[3] != "") {
        name = array[0];
        key = array[1];
        length = array[2];
    }
    else {
        name = array[0];
        key = array[1];
    }


    //Make Decision of Input
    if(name == "declscal") {
        declscal(arr, key, -1, 1);
    } else if (name == "declarr") {
        declarr(arr, key, length);
    } else if (name == "label") {
        label(arr, key);
    } else if (name == "gosublabel") {
        gosublabel(arr, key);
    } else if (name == "start") {
        start(arr);
    } else if (name == "end") {
        end(arr);
    } else if (name == "exit") {
        exit(arr);
    } else if (name == "jump") {
        jump(arr, key);
    } else if (name == "jumpzero") {
        jumpzero(arr, key);
    } else if (name == "jumpnzero") {
        jumpnzero(arr, key);
    } else if (name == "gosub") {
        gosub(arr, key);
    } else if (name == "return") {
        returnF(arr);
    } else if (name == "pushscal") {
        pushscal(arr, key);
    } else if (name == "pusharr") {
        pusharr(arr, key);
    } else if (name == "pushi") {
        pushi(arr, key);
    } else if (name == "pop") {
        pop(arr);
    } else if (name == "popscal") {
        popscal(arr, var);
    } else if (name == "dup") {
        dup(arr);
    } else if (name == "swap") {
        swapF(arr);
    } else if (name == "add") {
        add(arr, key);
    } else if (name == "negate") {
        negate(arr, key);
    } else if (name == "mul") {
        mul(arr, key);
    } else if (name == "div") {
        div(arr, key);
    } else if (name == "printtos") {
        printos(arr, key);
    } else if (name == "prints") {
        prints(arr, key);
    }

}


//Statements Functions - -1 : later changeable value, -2 : Empty value
void Statements::declscal(std::string arr[], std::string var, int location, int length) {
    arr[0] = "-2"; arr[1] = "-2"; arr[2] = var; arr[3] = location; arr[4] = length;
}

void Statements::declarr(std::string arr[], std::string var, int location, int length) {
    arr[0] = "-2"; arr[1] = "-2"; arr[2] = var; arr[3] = location; arr[4] = length;
}

void Statements::start(std::string arr[]) {
    InstructionBuffer("OP_START_PROGRAM", -1);
    arr[0] = "OP_START_PROGRAM";
    arr[1] = "-1"; arr[2] = "-2"; arr[3] = "-2"; arr[4] = "-2";
}

void Statements::end(std::string arr[]) {
    arr[0] = "END";
    arr[1] = "-2"; arr[2] = "-2"; arr[3] = "-2"; arr[4] = "-2";
}

void Statements::exit(std::string arr[]) {
    InstructionBuffer("OP_EXIT_PROGRAM", 0);
    arr[0] = "OP_EXIT_PROGRAM";
    arr[1] = "-2"; arr[2] = "-2"; arr[3] = "-2"; arr[4] = "-2";
}

/*
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
