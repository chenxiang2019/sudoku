#include "sudokuJudger.h"
#include <string.h>
#include <iostream>
using namespace std;

bool SudokuJudger::SudokuisSolved(int input[9][9]) {
    int i, j; 

    // judging if a line/column/block is legal or not
    int testLine[10];
    int testColumn[10];
    int testBlock[10];

    for (i = 0; i < 9; i++) {
        // initial the testLine 
        memset(testLine, 0, sizeof(testLine));
        memset(testColumn, 0, sizeof(testColumn));
        memset(testBlock, 0, sizeof(testBlock));

        // In the following codes, I fulfill a index 
        // to judge if a number is occurred.
        for (j = 0; j < 9; j++) {
            // index = the current number 
            int index = input[i][j];
            
            // test*[index] == 1 means that the 
            // number has occurred.
            if (testLine[index] == 1) { 
                cout << "Error1 occurred in line " << i << " column " << j << "\n";
                return false;
            } else {
                testLine[index] = 1;
            }
        }

        for (j = 0; j < 9; j++) {
            int index = input[j][i];

            if (testColumn[index] == 1) {
                cout << "Error2 occurred in line " << j << " column " << i << "\n";
                return false;
            } else {
                testColumn[index] = 1;
            }
        }

        int blockNumber = i+1;

        // Using block number to calculate 
        // the place of top-left number of
        // each block.
        int topleftLine = 0, topleftColumn = 0;
            
        // calculate the column of top-left number
        if (blockNumber%3 == 0) {
            topleftColumn = 6;
        } else if (blockNumber%3 == 1) {
            topleftColumn = 0;
        } else if (blockNumber%3 == 2){
            topleftColumn = 3;
        }
            
        // calculate the line of top-left number
        if (blockNumber/3.0 <= 1) {
            topleftLine = 0;
        } else if (blockNumber/3.0 > 1 && blockNumber/3.0 <= 2) {
            topleftLine = 3;
        } else if (blockNumber/3.0 > 2) {
            topleftLine = 6;
        }

        int lineIndex = 0, columnIndex = 0;
        int currentNumber = 0, currentline = 0, currentcolumn = 0;

        for (lineIndex = 0; lineIndex < 3; lineIndex++) {
            for (columnIndex = 0; columnIndex < 3; columnIndex++) {
                // calculate the current place based on left-top place and index
                currentline = topleftLine+lineIndex;
                currentcolumn = topleftColumn+columnIndex;

                currentNumber = input[currentline][currentcolumn];
                if (testBlock[currentNumber] == 1) {
                    cout << "Error3 occurred in line " << currentline << " column " << currentcolumn << "\n";
                    return false;
                } else {
                    testBlock[currentNumber] = 1;
                }
            }
        }
    }

    // the following codes enable the check of two diagonal lines.

    // for two diagonal line: 
    // left-to-right(L2R) and right-to-left(R2L) checking
    /*int testDiagonal_L2R[10];
    int testDiagonal_R2L[10];

    memset(testDiagonal_L2R, 0, sizeof(testDiagonal_L2R));
    memset(testDiagonal_R2L, 0, sizeof(testDiagonal_R2L));

    // using the current number as the index 
    int indexL2R = 0, indexR2L = 0;
  
    for (i = 0; i < 9; i++) {
        indexL2R = input[i][i];
        indexR2L = input[i][9-i-1];

        if (testDiagonal_L2R[indexL2R] == 1 || testDiagonal_R2L[indexR2L] == 1) {
            if (testDiagonal_L2R[indexL2R] = 1) {
                cout << "L2R Error4 occurred in line " << i << " column " << i << "\n";
            } else {
                cout << "R2L Error4 occurred in line " << i << " column " << 9-i-1 << "\n";
            }
            return false;
        } else {
            testDiagonal_L2R[indexL2R] = 1;
            testDiagonal_R2L[indexR2L] = 1;
        }
    }*/

    return true;
}
