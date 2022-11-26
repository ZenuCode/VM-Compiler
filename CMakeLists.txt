cmake_minimum_required(VERSION 3.23)
project(Step1)

set(CMAKE_CXX_STANDARD 11)

add_executable(Step1 main.cpp OutputAndTestCases/Input/0StartExit SymbolTable.cpp SymbolTable.h Statements.cpp Statements.h StatementBuffer.cpp StatementBuffer.h)
