#ifndef IOER_H
#define IOER_H
#include <iostream>
#include <fstream>
using namespace std;

class SudokuIOer {
public:
    SudokuIOer() {
    }
    void outputFile(int solution[9][9], fstream sudokuFile);
};

#endif
