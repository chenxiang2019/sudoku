#ifndef GENERATOR_H
#define GENERATOR_H
#include <string.h>

class SudokuGenerator {
public:
    SudokuGenerator() {
        memset(solution, 0, sizeof(solution));
    }

    int generateNumber(int inputAvailable[10], int index);
    bool Generator();

    // print the calculated solutions
    void Printer();

private:
    int solution[10][10];
};

#endif