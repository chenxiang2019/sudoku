# sudoku
sudoku: giving reasonable sudoku solutions 

## Usage:

1.Linux:

```
$ cd SudokuProject
$ ./compile.sh
$ touch sudoku.txt
$ ./main -c 10 // generate 10 sudoku solutions
```

2.Windows:

```
$ cd BIN/
$ sudoku.exe -c 10 // generate 10 sudoku solutions
```
## Code Coverage Examination

Commands for generating locv reports in Linux(Ubuntu 14.04):

```
$ ./compile.sh

$ ./main -c 100 // generate 100 solutions

$ ./test_report.sh
```

You could check the code coverage result on `SudokuProject/result/`:

![](https://github.com/Wasdns/sudoku/blob/master/Report/lcov.png)
