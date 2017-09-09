#include "sudokuIO.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

void SudokuIOer::outputFile(int solution[9][9], fstream sudokuFile) {
    int i, j;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (j < 8) {
                sudokuFile << solution[i][j] << " ";
            } else {
                sudokuFile << solution[i][j] << endl;
            }
        }
    }
    sudokuFile << "\n";
}
