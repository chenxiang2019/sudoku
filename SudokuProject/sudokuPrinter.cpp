#include "sudokuPrinter.h"
#include <iostream>
using namespace std;

void SudokuPrinter::Printer(int solution[9][9]) {
    int i, j;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (j < 8) {
                cout << solution[i][j] << " ";
            } else {
                cout << solution[i][j] << endl;
            }
        }
    }
}