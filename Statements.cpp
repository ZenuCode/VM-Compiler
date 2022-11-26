#include <string>
#include <regex>
#include <cstring>
#include "Statements.h"
#include "SymbolTable.h"
#include "StatementBuffer.h"
#include "StringBuffer.h"

Statements::Statements() {}

void Statements::processStmt(std::string input, StatementBuffer *Instructions, SymbolTable *Symbols, StringBuffer *Strings) {
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
        jump(Instructions, key);
    } else if (name == "jumpzero") {
        jumpzero(Instructions, key);
    } else if (name == "jumpnzero") {
        jumpnzero(Instructions, key);
    } else if (name == "gosub") {
        gosub(Instructions, key);
    } else if (name == "return") {
        returnF(Instructions, Symbols);
    } else if (name == "pushscal") {
        pushscal(Instructions, Symbols, key);
    } else if (name == "pusharr") {
        pusharr(Instructions, Symbols, key);
    } else if (name == "pushi") {
        pushi(Instructions, key);
    } else if (name == "pop") {
        pop(Instructions);
    } else if (name == "popscal") {
        popscal(Instructions, Symbols, key);
    } else if (name == "poparr") {
        poparr(Instructions, Symbols, key);
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
        prints(Instructions, Strings, key);
    }
}

//////////////

void Statements::declscal(SymbolTable *Symbols, std::string key) {
    Symbols->input(Symbols, key, 0, 1);
}

void Statements::declarr(SymbolTable *Symbols, std::string key, std::string length) {
    int num = std::stoi(length);
    Symbols->input(Symbols, key, num, 0);
}

void Statements::label(SymbolTable *Symbols, std::string key, int position) {
    Symbols->input(Symbols, key, position, 0);
}

void Statements::gosublabel(StatementBuffer *Instructions, SymbolTable *Symbols, std::string key, int position) {
    Instructions->fourInput(Instructions, "OP_ENTER_SUBROUTINE", -1, key);
    Symbols->input(Symbols, key, position, 0);
    Symbols->subroutine[Symbols->subRouON] = Symbols->Symbols;
    Symbols->subRouON++;
    Symbols->Symbols = Symbols->subroutine[Symbols->subRouON];
}

void Statements::start(StatementBuffer *Instructions) {
    Instructions->threeInput(Instructions, "OP_START_PROGRAM", 0);
}

void Statements::end(StatementBuffer *Instructions) {
}

void Statements::exit(StatementBuffer *Instructions) {
    Instructions->threeInput(Instructions, "OP_EXIT_PROGRAM", 0);
}

void Statements::jump(StatementBuffer *Instructions, std::string val) {
    Instructions->fourInput(Instructions, "OP_JUMP", -1, val);
}

void Statements::jumpzero(StatementBuffer *Instructions, std::string) {
    Instructions->twoInput(Instructions, "OP_JUMPZERO");
}

void Statements::jumpnzero(StatementBuffer *Instructions, std::string val) {
    Instructions->twoInput(Instructions, "OP_JUMPNZERO");
}

void Statements::gosub(StatementBuffer *Instructions, std::string label) {
    Instructions->fourInput(Instructions, "OP_GOSUB", -1, label);
}

void Statements::returnF(StatementBuffer *Instructions, SymbolTable *Symbols) {
    Instructions->threeInput(Instructions, "OP_RETURN", 0);

    int index = 0;
    for(std::map<int, std::pair<std::pair<std::string, int>, std::string>>::const_iterator it = Instructions->Instructions.begin(); it != Instructions->Instructions.end(); ++it) {
        if(it->second.first.first == "OP_ENTER_SUBROUTINE") {
            index = it->first;
            break;
        }
    }
    Instructions->Instructions[index].first.second = Symbols->subMem[Symbols->subRouON];
    Symbols->subRouON--;
    Symbols->Symbols = Symbols->subroutine[Symbols->subRouON];
}

void Statements::pushscal(StatementBuffer *Instructions, SymbolTable *Symbols, std::string var) {
    int num = Symbols->Symbols[var].first;
    Instructions->fourInput(Instructions, "OP_PUSHSCALAR", num, var);
}

void Statements::pusharr(StatementBuffer *Instructions, SymbolTable *Symbols, std::string var) {
    int num = Symbols->Symbols[var].first;
    Instructions->fourInput(Instructions, "OP_PUSHARRAY", num, var);
}

void Statements::pushi(StatementBuffer *Instructions, std::string var) {
    Instructions->threeInput(Instructions, "OP_PUSHI", std::stoi(var));
}

void Statements::pop(StatementBuffer *Instructions) {
    Instructions->twoInput(Instructions, "OP_POP");
}

void Statements::popscal(StatementBuffer *Instructions, SymbolTable *Symbols, std::string var) {
    int num = Symbols->Symbols[var].first;
    Instructions->fourInput(Instructions, "OP_POPSCALAR", num, var);
}

void Statements::poparr(StatementBuffer *Instructions, SymbolTable *Symbols, std::string var) {
    int num = Symbols->Symbols[var].first;
    Instructions->fourInput(Instructions, "OP_POPARRAY", num, var);
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

void Statements::prints(StatementBuffer *Instructions, StringBuffer *Strings, std::string input) {
    Instructions->threeInput(Instructions, "OP_PRINTS", Strings->count);
    Strings->insertStr(Strings, input, Strings->count);
}

void Statements::processPrint(StatementBuffer Instructions, SymbolTable Symbols, StringBuffer Strings) {
    for(int i = 0; i < Strings.count; i++) {
        std::cout << Strings.stringBuff[i] << std::endl;
    }
    Strings.count = 0;

    Instructions.labelCount = 0;
    std::string temp;

    for(std::map<int, std::pair<std::pair<std::string, int>, std::string>>::const_iterator it = Instructions.Instructions.begin(); it != Instructions.Instructions.end(); ++it) {
        if(it->second.first.second == -1) {
            temp = Instructions.Instructions[it->first].second;
            Instructions.Instructions[it->first].first.second = Symbols.Symbols[temp].first;
        }
    }

    for(std::map<int, std::pair<std::pair<std::string, int>, std::string>>::iterator it = Instructions.Instructions.begin(); it != Instructions.Instructions.end(); ++it) {
        if(it->second.first.first == "OP_JUMP") {
            std::cout << "Jump" << " " << it->second.first.second << std::endl;
        } else if(it->second.first.first == "OP_JUMPZERO") {
            std::cout << "JumpZero" << " " << it->second.first.second << std::endl;
        } else if(it->second.first.first == "OP_JUMPNZERO") {
            std::cout << "JumpNZero" << " " << it->second.first.second << std::endl;
        } else if(it->second.first.first == "OP_GOSUB") {
            for(std::map<int, std::pair<std::pair<std::string, int>, std::string>>::const_iterator in = Instructions.Instructions.begin(); in != Instructions.Instructions.end(); ++in) {
                if(in->second.second == it->second.second && in->first != it->first) {
                    it->second.first.second = in->first;;
                }
            }
            std::cout << "GoSub" << " " << it->second.first.second << std::endl;
        } else if(it->second.first.first == "OP_RETURN") {
            std::cout << "Return" << " " << std::endl;
        } else if(it->second.first.first == "OP_ENTER_SUBROUTINE") {
            std::cout << "GoSubLabel" << " " << it->second.first.second << std::endl;
        } else if(it->second.first.first == "OP_EXIT_SUBROUTINE") {
            std::cout << "ExitSub" << std::endl;
        } else if(it->second.first.first == "OP_START_PROGRAM") {
            int count = 0;
            for(std::map<std::string, std::pair<int, int>>::const_iterator in = Symbols.Symbols.begin(); in != Symbols.Symbols.end(); in++) {
                count += in->second.second;
            }
            std::cout << "Start " << count << std::endl;
        } else if(it->second.first.first == "OP_EXIT_PROGRAM") {
            std::cout << "Exit" << std::endl;
        } else if(it->second.first.first == "OP_PUSHSCALAR") {
            std::cout << "PushScalar" << " " << it->second.first.second << std::endl;
        } else if(it->second.first.first == "OP_PUSHARRAY") {
            std::cout << "PushArray" << " " << it->second.first.second << std::endl;
        } else if(it->second.first.first == "OP_PUSHI") {
            std::cout << "PushI" << " " << it->second.first.second << std::endl;
        } else if(it->second.first.first == "OP_POPSCALAR") {
            std::cout << "PopScalar" << " " << it->second.first.second << std::endl;
        } else if(it->second.first.first == "OP_POPARRAY") {
            std::cout << "PopArray" << " " << it->second.first.second << std::endl;
        } else if(it->second.first.first == "OP_POP") {
            std::cout << "Pop" << std::endl;
        } else if(it->second.first.first == "OP_DUP") {
            std::cout << "Dup" << std::endl;
        } else if(it->second.first.first == "OP_SWAP") {
            std::cout << "Swap" << std::endl;
        } else if(it->second.first.first == "OP_ADD") {
            std::cout << "Add" << std::endl;
        } else if(it->second.first.first == "OP_NEGATE") {
            std::cout << "Negate" << std::endl;
        } else if(it->second.first.first == "OP_MUL") {
            std::cout << "Mul" << std::endl;
        } else if(it->second.first.first == "OP_DIV") {
            std::cout << "Div" << std::endl;
        } else if(it->second.first.first == "OP_PRINTS") {
            std::cout << "Prints" << " " << Strings.count << std::endl;
            Strings.count++;
        } else if(it->second.first.first == "OP_PRINTTOS") {
            std::cout << "PrintTOS" << std::endl;
        }
    }
}


