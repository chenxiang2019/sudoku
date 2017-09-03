#include "sudokuJudger.h"
#include <stdlib.h>
#include <iostream>
#include <unistd.h> // for linux
// #include <windows.h> // for windows
using namespace std;

int main() {
    int input[9][9];
    int i, j;

    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            cin >> input[i][j];
        }
    }
    SudokuJudger sudokuJudger1;
    bool sudokuResult = sudokuJudger1.SudokuisSolved(input);
    if (sudokuResult) {
        cout << "Congratulations!" << endl;
    }
    return 0;
}