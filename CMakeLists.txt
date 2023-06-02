cmake_minimum_required(VERSION 3.25)
project(CPlus_Library)

set(CMAKE_CXX_STANDARD 17)


add_library(CPlus_Library "Lexical analysis.cpp" "Predictive Analysis.h" "Predictive Analysis.cpp" calculator.h calculator.cpp "Recursive descent.cpp" "Recursive descent.h" "code convert.cpp" "code convert.h")
