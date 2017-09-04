#include "sudokuGenerator.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

bool SudokuGenerator::Generator() {
    int i, j, k;
    memset(solution, 0, sizeof(solution));

    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            // specific requirments: 09
            if (i == 0 && j == 0) {
                solution[0][0] = (0+9)%9+1;
                continue;
            }
            cout << "life is stucked here: place 1" << endl;
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
            if (isImpossible) {
                cout << "no answer for current place: place 2" << endl;
                return false;
            }

            // randomly choose a number from availableNumbers 
            int randomIndex = 0;

            // get array length
            length = index-1;
            
            srand(time(NULL));
            randomIndex = rand()%length+1;
            
            cout << "the chosen number is: " << availableNumbers[randomIndex] << endl;
            solution[i][j] = availableNumbers[randomIndex];
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