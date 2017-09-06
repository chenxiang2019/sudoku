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

    int solution[9][9];
};

#endif