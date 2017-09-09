#include "sudokuJudger.h"
#include "sudokuGenerator.h"
#include "sudokuPrinter.h"
#include "sudokuIO.h"
#include "sudokuExceptionInspector.h"
#include <stdlib.h>
#include <fstream>
// #include <unistd.h>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 3) {
        cout << "Error occurs when parsing arguments." << endl;
        cout << "Usage: sudoku.exe -c [N: a number]" << endl;
        return 1;
    }
    
    int solutionNumber;
    SudokuExceptionInspector sudokuExceptionInspector;
    try {
        solutionNumber = sudokuExceptionInspector.parser(argv[2]);
    } catch(ParserException) {
        cout << "Error occurs when parsing arguments." << endl;
        cout << "Usage: sudoku.exe -c [N: a number]" << endl;
        cout << "Please check your input number." << endl;
        return 1;
    }

    SudokuGenerator sudokuGenerator;
    SudokuIOer sudokuIOer;
    // SudokuPrinter sudokuPrinter;

    fstream sudokuFile;
    // open sudoku.txt 
    sudokuFile.open(filename, ios::app);

    bool signal = false;

    for (int i = 0; i < solutionNumber; i++) {
        signal = sudokuGenerator.Generator();
        if (signal) {
            sudokuGenerator.increaseRandomSeed();
            sudokuIOer.outputFile(sudokuGenerator.solution, sudokuFile);
        } else {
            cout << "Error occurs when applying sudokuGenerator." << endl;
            return 1;
        }
    }

    // close sudoku.txt
    sudokuFile.close();

    return 0;
}
