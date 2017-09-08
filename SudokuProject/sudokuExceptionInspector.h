#ifndef EXCEPTION_INSPECTOR_H
#define EXCEPTION_INSPECTOR_H

// class for reporting exception
class ParserException {
public:
	ParserException() { };
};

class SudokuExceptionInspector {
public:
	SudokuExceptionInspector() { };
    bool isNumber(char number[]);
    int parser(char number[]) throw(ParserException);
};

#endif