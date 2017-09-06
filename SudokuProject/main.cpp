#include "sudokuJudger.h"
#include "sudokuGenerator.h"
#include "sudokuPrinter.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

int main() {
    int input[9][9];
    int i, j;

    bool signal = false;
    SudokuGenerator sudokuGenerator;
    while (!signal) {
        signal = sudokuGenerator.Generator();
    }
    SudokuPrinter sudokuPrinter;
    sudokuPrinter.Printer(sudokuGenerator.solution);

    /*for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            cin >> input[i][j];
        }
    }
    SudokuJudger sudokuJudger1;
    bool sudokuResult = sudokuJudger1.SudokuisSolved(input);
    if (sudokuResult) {
        cout << "Congratulations!" << endl;
    }*/
    return 0;
}