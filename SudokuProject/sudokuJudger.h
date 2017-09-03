#ifndef JUDGER_H
#define JUDGER_H

class SudokuJudger {
public: 
    SudokuJudger() { 
    };
    
    // SudokuisSolved: judge if the input is a
    // reasonable solution of sudoku or not.
    bool SudokuisSolved(int input[9][9]);
};

#endif
