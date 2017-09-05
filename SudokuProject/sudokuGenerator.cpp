#include "sudokuGenerator.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

bool SudokuGenerator::Generator1() {
    int i, j, k;
    memset(solution, 0, sizeof(solution));

    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            // specific requirments: 09
            if (i == 0 && j == 0) {
                solution[0][0] = (0+9)%9+1;
                continue;
            }

            // possible number, satisfy the requirements
            // possibleNumber[number] = 1: the number is impossible
            int possibleNumber[10];
            memset(possibleNumber, 0, sizeof(possibleNumber));

            // satisfy the line requirments
            for (k = 0; k < 9; k++) {
                int index = solution[i][k];
                possibleNumber[index] = 1;
            }
                       
            // satisfy the column requirments
            for (k = 0; k < 9; k++) {
                int index = solution[k][i];
                possibleNumber[index] = 1;
            } 
            
            // satisfy the block requirments
            int topleftLine = (i/3)*3, topleftColumn = (j/3)*3;
            int indexLine = 0, indexColumn = 0;
            for (indexLine = 0; indexLine < 3; indexLine++) {
                for (indexColumn = 0; indexColumn < 3; indexColumn++) {
                    int number = solution[topleftLine+indexLine][indexColumn+indexColumn];
                    possibleNumber[number] = 1;
                }
            }
            
            // array used to store possible numbers
            int availableNumbers[15], index = 1, length = 0;

            // check if all the number are impossible or not
            bool isImpossible = true;
            for (k = 1; k < 10; k++) {
                if (possibleNumber[k] == 0) {
                    isImpossible = false;
                    availableNumbers[index] = k;
                    index++;
                }
            }
            
            // if impossible, recirculate
            if (isImpossible) return false;

            // randomly choose a number from availableNumbers 
            int randomIndex = 0;

            // get array length
            length = index-1;
            
            srand(time(NULL));
            randomIndex = rand()%length+1;
            
            solution[i][j] = availableNumbers[randomIndex];
        }
    }
    return true;
}

/**
 * Generate legal number for specific array space,
 * based on the limitations of line, column and block.
 *  
 * If the generateNumber did not find available number,
 * it will return -1 to notice that the process is failed.
 */
int SudokuGenerator::generateNumber(int index) {
    // Based on line/column/block limitations to remove illegal numbers.
    // available[number] = 0: the number is available;
    // available[number] = 1: the number is illegal;
    int available[10];
    memset(available, 0, sizeof(available));

    // store the possible number in numberStorage
    int numberStorage[10], length = 0;
    memset(numberStorage, 0, sizeof(numberStorage));

    // get the line and column number based on index
    int lineIndex = index/9, columnIndex = index%9;

    // get the first place in terms of (line, column) based on 
    // the current place, i.e.(lineIndex, columnIndex)
    int blockFirstLine = (lineIndex/3)*3;
    int blockFirstColumn = (columnIndex/3)*3;

    // remove impossible numbers based on line limitation
    for (int i = 0; i < columnIndex; i++) {
        int currentNumber = solution[lineIndex][i];
        available[currentNumber] = 1;
    }

    // remove impossible numbers based on column limitation
    for (int i = 0; i < lineIndex; i++) {
        int currentNumber = solution[i][columnIndex];
        available[currentNumber] = 1;
    }

    // remove impossible numbers based on block limitation
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            // deduce current number based on the space of 
            // first number in the block
            int currentLine = blockFirstLine+i;
            int currentColumn = blockFirstColumn+j;
            int currentNumber = solution[currentLine][currentColumn];
            available[currentNumber] = 1;
        }
    }

    // search for available number
    for (int i = 1; i < 10; i++) {
        if (available[i] == 0) {
            numberStorage[length] = i;
            length++;
        }
    }

    // if no available number found, return -1
    if (length == 0) {
        cout << "Error: no such number found." << endl;
        return -1;
    } else { // otherwise, randomly choose one available number
        srand(time(NULL));
        int randomIndex = rand()%length;
        return numberStorage[randomIndex];
    }
}

bool SudokuGenerator::Generator2() {
    // initial the solution array
    memset(solution, 0, sizeof(solution));
    solution[0][0] = (0+9)%9+1;

    int i = 1;
    // traverse the whole array 
    while (i < 81) {
        int getNumber = generateNumber(i);
        // if the getNumber = -1, mark i as 1, restart the process
        if (getNumber == -1) {
            i = 1;

            // initial the solution array again
            memset(solution, 0, sizeof(solution));
            solution[0][0] = (0+9)%9+1;
        } else { // update the solution array
            int lineIndex = i/9, columnIndex = i%9; 
            solution[lineIndex][columnIndex] = getNumber;
            i++;
        }
    }

    return true;
}

void SudokuGenerator::Printer() {
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