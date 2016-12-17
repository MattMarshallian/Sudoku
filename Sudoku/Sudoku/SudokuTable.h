#pragma once

#include <vector>

#include "Cell.h"

const static int SUDOKU_MAGIC_NUMBER = 9;
const static int NUMBERS_IN_SUDOKU = SUDOKU_MAGIC_NUMBER * SUDOKU_MAGIC_NUMBER;

class SudokuTable
{
public:
    SudokuTable();
    ~SudokuTable();

    std::vector<Cell*> allpCells;

private:
    int setFixRow(Cell* pCell);
    int setFixColumn(Cell* pCell);
    int setFixSquare(Cell* pCell);
};

