#include <string>
#include <regex>
#include <cstring>
#include "Statements.h"
#include "SymbolTable.h"
#include "StatementBuffer.h"

Statements::Statements() {}

void Statements::processStmt(std::string input, StatementBuffer *Instructions, SymbolTable *Symbols) {
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

    name = array[0];
    if(array[2] == "") {
        key = array[1];
        length = "-1";
    } else {
        key = array[1];
        length = array[2];
    }

    int position = Instructions->count;

    //Make Decision of Input
    if(name == "declscal") {
        declscal(Symbols, key);
    } else if (name == "declarr") {
        declarr(Symbols, key, length);
    } else if (name == "label") {
        label(Symbols, key, position);
    } else if (name == "gosublabel") {
        gosublabel(Instructions, Symbols, key, position);
    } else if (name == "start") {
        start(Instructions);
    } else if (name == "end") {
        end(Instructions);
    } else if (name == "exit") {
        exit(Instructions);
    } else if (name == "jump") {
        jump(Instructions);
    } else if (name == "jumpzero") {
        jumpzero(Instructions, key);
    } else if (name == "jumpnzero") {
        jumpnzero(Instructions, key);
    } else if (name == "gosub") {
        gosub(Instructions, Symbols, key, position);
    } else if (name == "return") {
        returnF(Instructions);
    } else if (name == "pushscal") {
        pushscal(Instructions, key);
    } else if (name == "pusharr") {
        pusharr(Instructions, key);
    } else if (name == "pushi") {
        pushi(Instructions, key);
    } else if (name == "pop") {
        pop(Instructions);
    } else if (name == "popscal") {
        popscal(Instructions, key);
    } else if (name == "poparr") {
        poparr(Instructions, key);
    } else if (name == "dup") {
        dup(Instructions);
    } else if (name == "swap") {
        swapF(Instructions);
    } else if (name == "add") {
        add(Instructions);
    } else if (name == "negate") {
        negate(Instructions);
    } else if (name == "mul") {
        mul(Instructions);
    } else if (name == "div") {
        div(Instructions);
    } else if (name == "printtos") {
        printtos(Instructions);
    } else if (name == "prints") {
        prints(Instructions, Symbols, key);
    }
}

//Statements Functions - -1 : later changeable value, -2 : Empty value
//SymbolTable Statements::declscal(SymbolTable Symbols, std::string key) {
//    Symbols = Symbols.input(Symbols, key, 0, 1)
//}

void Statements::declscal(SymbolTable *Symbols, std::string key) {
    Symbols->input(Symbols, key, 0, 1);
}

void Statements::declarr(SymbolTable *Symbols, std::string key, std::string length) {
    Symbols->input(Symbols, key, 0, std::stoi(length));
}

void Statements::label(SymbolTable *Symbols, std::string key, int position) {
    Symbols->input(Symbols, key, position, 0);
}

void Statements::gosublabel(StatementBuffer *Instructions, SymbolTable *Symbols, std::string key, int position) {
    Instructions->threeInput(Instructions, "OP_ENTER_SUBROUTINE", position);
    Symbols->input(Symbols, key, position, 0);
}

void Statements::start(StatementBuffer *Instructions) {
    Instructions->twoInput(Instructions, "OP_START_PROGRAM");
}

void Statements::end(StatementBuffer *Instructions) {
}

void Statements::exit(StatementBuffer *Instructions) {
    Instructions->threeInput(Instructions, "OP_EXIT_PROGRAM", 0);
}

void Statements::jump(StatementBuffer *Instructions) {
    Instructions->twoInput(Instructions, "OP_JUMP"); //Need to think of way how to L1, L2
}

void Statements::jumpzero(StatementBuffer *Instructions, std::string) {
    Instructions->twoInput(Instructions, "OP_JUMPZERO");
}

void Statements::jumpnzero(StatementBuffer *Instructions, std::string) {
    Instructions->twoInput(Instructions, "OP_JUMPNZERO");
}

void Statements::gosub(StatementBuffer *Instructions, SymbolTable *Symbols, std::string label, int position) {
    Instructions->twoInput(Instructions, "OP_GOSUB");
    Symbols->input(Symbols, label, position, 0);
}

void Statements::returnF(StatementBuffer *Instructions) {
    Instructions->twoInput(Instructions, "OP_RETURN");
}

void Statements::pushscal(StatementBuffer *Instructions, std::string var) {
    Instructions->threeInput(Instructions, "OP_PUSHSCALAR", std::stoi(var));
}

void Statements::pusharr(StatementBuffer *Instructions, std::string var) {
    Instructions->threeInput(Instructions, "OP_PUSHARR", std::stoi(var));
}

void Statements::pushi(StatementBuffer *Instructions, std::string var) {
    Instructions->threeInput(Instructions, "OP_PUSHI", std::stoi(var));
}

void Statements::pop(StatementBuffer *Instructions) {
    Instructions->twoInput(Instructions, "OP_POP");
}

void Statements::popscal(StatementBuffer *Instructions, std::string) {
    Instructions->twoInput(Instructions, "OP_POPSCAL");
}

void Statements::poparr(StatementBuffer *Instructions, std::string) {
    Instructions->twoInput(Instructions, "OP_POPARRAY");
}

void Statements::dup(StatementBuffer *Instructions) {
    Instructions->twoInput(Instructions, "OP_DUP");
}

void Statements::swapF(StatementBuffer *Instructions) {
    Instructions->twoInput(Instructions, "OP_SWAP");
}

void Statements::add(StatementBuffer *Instructions) {
    Instructions->twoInput(Instructions, "OP_ADD");
}

void Statements::negate(StatementBuffer *Instructions) {
    Instructions->twoInput(Instructions, "OP_NEGATE");
}

void Statements::mul(StatementBuffer *Instructions) {
    Instructions->twoInput(Instructions, "OP_MUL");
}

void Statements::div(StatementBuffer *Instructions) {
    Instructions->twoInput(Instructions, "OP_DIV");
}

void Statements::printtos(StatementBuffer *Instructions) {
    Instructions->twoInput(Instructions, "OP_PRINTTOS");
}

void Statements::prints(StatementBuffer *Instructions, SymbolTable *Symbols, std::string input) {
    Instructions->twoInput(Instructions, "OP_PRINT");
    Symbols->input(Symbols, input, 0, input.length());
}

void Statements::processPrint(StatementBuffer Instructions, SymbolTable Symbols) {

    int count = 0;
    for(std::map<int, std::pair<std::string, int> >::const_iterator it = Instructions.Instructions.begin(); it != Instructions.Instructions.end(); ++it) {
        if(it->second.first == "OP_JUMP") {
            std::cout << "Jump" << " " << it->second.second << std::endl;
        } else if(it->second.first == "OP_JUMPZERO") {
            std::cout << "JumpZero" << " " << it->second.second << std::endl;
        } else if(it->second.first == "OP_JUMPNZERO") {
            std::cout << "JumpNZero" << " " << it->second.second << std::endl;
        } else if(it->second.first == "OP_GOSUB") {
            std::cout << "GoSub" << " " << it->second.second << std::endl;
        } else if(it->second.first == "OP_RETURN") {
            std::cout << "Return" << " " << it->second.second << std::endl;
        } else if(it->second.first == "OP_ENTER_SUBROUTINE") {
            std::cout << "GoSubLabel" << " " << it->second.second << std::endl;
        } else if(it->second.first == "OP_EXIT_SUBROUTINE") {
            std::cout << "ExitSub" << std::endl;
        } else if(it->second.first == "OP_START_PROGRAM") {
            std::cout << "Start 0" << std::endl;
        } else if(it->second.first == "OP_EXIT_PROGRAM") {
            std::cout << "Exit" << std::endl;
        } else if(it->second.first == "OP_PUSHSCALAR") {
            std::cout << "PushScalar" << " " << it->second.second << std::endl;
        } else if(it->second.first == "OP_PUSHARRAY") {
            std::cout << "PushArray" << " " << it->second.second << std::endl;
        } else if(it->second.first == "OP_PUSHI") {
            std::cout << "PushI" << " " << it->second.second << std::endl;
        } else if(it->second.first == "OP_POPSCALAR") {
            std::cout << "PopScalar" << " " << it->second.second << std::endl;
        } else if(it->second.first == "OP_POPARRAY") {
            std::cout << "PopArray" << " " << it->second.second << std::endl;
        } else if(it->second.first == "OP_POP") {
            std::cout << "Pop" << std::endl;
        } else if(it->second.first == "OP_DUP") {
            std::cout << "Dup" << std::endl;
        } else if(it->second.first == "OP_SWAP") {
            std::cout << "Swap" << std::endl;
        } else if(it->second.first == "OP_ADD") {
            std::cout << "Add" << std::endl;
        } else if(it->second.first == "OP_NEGATE") {
            std::cout << "Negate" << std::endl;
        } else if(it->second.first == "OP_MUL") {
            std::cout << "Mul" << std::endl;
        } else if(it->second.first == "OP_DIV") {
            std::cout << "Div" << std::endl;
        } else if(it->second.first == "OP_PRINTS") {
            std::cout << "Prints 0" << " " << it->second.second << std::endl;
        } else if(it->second.first == "OP_PRINTTOS") {
            std::cout << "PrintTOS" << std::endl;
        }
    }
}


