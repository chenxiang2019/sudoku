#include "sudokuIO.h"
#include <fstream>
#include <stdlib.h>
#include <iostream>
using namespace std;

void SudokuIOer::outputFile(int solution[9][9], char filename[]) {
    fstream sudokuFile;
    // open sudoku.txt 
    sudokuFile.open(filename, ios::app);

    // write the answer to sudoku.txt
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

    // close sudoku.txt
    sudokuFile.close();
}