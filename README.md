# VM-Compiler

Completion of a Virtual Machine in C++.

Takes inputs to parse and output the VM Compiler.

Used C++ not limited to Singleton, Containers, Maps/Vectors, Shared Pointers, etc.

1. step1 directory holds the code of the parsing stage. Takes in instructions and converts to virtual machine language which is readable for step 2 code. Output is stored in output.out to be sent to step2.

2. step2 directoy holds the code of the virtual machine stage. Takes the output.out from step1 to interprete the vm instructions and outputs to the console.

All code used with g++ -std=c+11 *.cpp
