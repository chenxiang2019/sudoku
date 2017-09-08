#include "sudokuExceptionInspector.h"
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;

bool SudokuExceptionInspector::isNumber(char number[]) {
    bool isNumber = true;

    if (number == NULL) {
        isNumber = false;
        return isNumber;
    }
    
    // get the length of the number
    int length = strlen(number);
    if (length == 0) {
        isNumber = false;
        return isNumber;
    }

    // if occurred a char, report error
    for (int i = 0; i < length; i++) {
        if (!isdigit(number[i])) {
        	 isNumber = false;
        	 return isNumber;
        }
    }

    return isNumber;
}

int SudokuExceptionInspector::parser(char number[]) throw(ParserException) {
	if (!isNumber(number)) {
        throw ParserException();
	} 
	return atoi(number);
}