#ifndef IOER_H
#define IOER_H
#include <fstream>
#include <iostream>
using namespace std;

class SudokuIOer {
public:
    SudokuIOer() {
    }
    void outputFile(int solution[9][9], ofstream& sudokuFile);
};

#endif
