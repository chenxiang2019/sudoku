#ifndef GENERATOR_H
#define GENERATOR_H
#include <string.h>

class SudokuGenerator {
public:
    SudokuGenerator() {
        memset(solution, 0, sizeof(solution));
    }

    // generate reasonable solutions
    bool Generator1();
    bool Generator2();
    int generateNumber(int index);
    // print the calculated solutions
    void Printer();

private:
    int solution[10][10];
};

#endif