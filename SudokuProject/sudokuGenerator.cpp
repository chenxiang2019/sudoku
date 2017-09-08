#include "sudokuGenerator.h"
#include <string.h>
#include <stdlib.h>
//#include <unistd.h> 
#include <time.h>
#include <iostream>
using namespace std;

void SudokuGenerator::increaseRandomSeed() {
    randomSeed++;
}

/**
 * Generate legal number for specific array space,
 * based on the limitations of line, column and block.
 *  
 * If the generateNumber did not find available number,
 * it will return -1 to notice that the process is failed.
 */
int SudokuGenerator::generateNumber(int inputAvailable[10], int index) {
    // Based on line/column/block limitations to remove illegal numbers.
    
    // initial available 
    int available[10];
    memset(available, 0, sizeof(available));
    for (int i = 0; i < 10; i++) {
        available[i] = inputAvailable[i];
    }

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
        // debug: cout << "Error: no such number found." << endl;
        return -1;
    } else { // otherwise, randomly choose one available number
        srand((unsigned)(time(NULL)+randomSeed));
        int randomIndex = rand()%length;
        return numberStorage[randomIndex];
    }
}

bool SudokuGenerator::Generator() {
    // initial the solution array
    memset(solution, 0, sizeof(solution));
    solution[0][0] = (0+9)%9+1;

    // available numbers in each place.
    // available[place][number] = 0: the number is available;
    // available[place][number] = 1: the number is illegal;
    int available[82][10];
    memset(available, 0, sizeof(available));

    // record previous trace
    int traverseRecorder[82];
    memset(traverseRecorder, 0, sizeof(traverseRecorder));

    traverseRecorder[0] = 1;
    
    // pointer of current place
    int currentPlacePointer = 1;

    int i = 1;

    // traverse the whole array 
    while (i < 81) {
        int getNumber = generateNumber(available[i], i);

        // if the getNumber = -1
        if (getNumber == -1) {
            // trace back to the previous place
            currentPlacePointer--;

            // mark the last chosen number as illegal.
            int lastChosenNumber = traverseRecorder[currentPlacePointer];
            available[currentPlacePointer][lastChosenNumber] = 1;

            // clean the traverseRecorder[currentPlacePointer]
            traverseRecorder[currentPlacePointer] = 0;
            
            i--; // back to previous place

            // initial the solution[lineIndex][columnIndex]
            int lineIndex = i/9, columnIndex = i%9; 
            solution[lineIndex][columnIndex] = 0;

            // as soon as the pointer trace back, 
            // clean the available[currentPlacePointer+1] array
            memset(available[currentPlacePointer+1], 0, sizeof(available[currentPlacePointer+1]));
            
            //sleep(1);
            //Printer();
        } else {
            // update the solution array
            int lineIndex = i/9, columnIndex = i%9; 
            solution[lineIndex][columnIndex] = getNumber;
            i++;

            // update currentPlacePointer and traverseRecorder
            traverseRecorder[currentPlacePointer] = getNumber;
            currentPlacePointer++;
        }
    }

    return true;
}
