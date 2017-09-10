lcov -d . -t sudoku -o sudoku.info -b . -c
genhtml -o result sudoku.info
