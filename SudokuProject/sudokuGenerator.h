#ifndef GENERATOR_H
#define GENERATOR_H
#include <string.h>

class SudokuGenerator {
public:
    SudokuGenerator() {
        randomSeed = 1;
        memset(solution, 0, sizeof(solution));
    }

    int generateNumber(int inputAvailable[10], int index);
    void increaseRandomSeed();
    bool Generator();
    
    int solution[9][9];

private:
    int randomSeed;
};

#endif