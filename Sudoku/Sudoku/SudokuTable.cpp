#include "stdafx.h"
#include "SudokuTable.h"


SudokuTable::SudokuTable()
{
    allpCells.reserve(NUMBERS_IN_SUDOKU);
    for (int i = 0; i < NUMBERS_IN_SUDOKU; ++i)
    {
        Cell* pCell = new Cell();
        allpCells.push_back(pCell);
        pCell->location.index = i;
        pCell->location.row = setFixRow(pCell);
        pCell->location.col = setFixColumn(pCell);
        pCell->location.square = setFixSquare(pCell);
    }
}


SudokuTable::~SudokuTable()
{
    for (auto c : allpCells) delete c;
}


int SudokuTable::setFixRow(Cell* pCell)
{
    return  pCell->location.index / SUDOKU_MAGIC_NUMBER;
}

int SudokuTable::setFixColumn(Cell* pCell)
{
    return pCell->location.index % SUDOKU_MAGIC_NUMBER;
}

int SudokuTable::setFixSquare(Cell* pCell)
{
    auto index = pCell->location.index;
    
    if (index / SUDOKU_MAGIC_NUMBER <= 2 && index % SUDOKU_MAGIC_NUMBER <= 2) return 0;
    if (index / SUDOKU_MAGIC_NUMBER <= 2 && index % SUDOKU_MAGIC_NUMBER <= 5) return 1;
    if (index / SUDOKU_MAGIC_NUMBER <= 2 && index % SUDOKU_MAGIC_NUMBER <= 8) return 2;
    if (index / SUDOKU_MAGIC_NUMBER <= 5 && index % SUDOKU_MAGIC_NUMBER <= 2) return 3;
    if (index / SUDOKU_MAGIC_NUMBER <= 5 && index % SUDOKU_MAGIC_NUMBER <= 5) return 4;
    if (index / SUDOKU_MAGIC_NUMBER <= 5 && index % SUDOKU_MAGIC_NUMBER <= 8) return 5;
    if (index / SUDOKU_MAGIC_NUMBER <= 8 && index % SUDOKU_MAGIC_NUMBER <= 2) return 6;
    if (index / SUDOKU_MAGIC_NUMBER <= 8 && index % SUDOKU_MAGIC_NUMBER <= 5) return 7;
    if (index / SUDOKU_MAGIC_NUMBER <= 8 && index % SUDOKU_MAGIC_NUMBER <= 8) return 8;

    return -1;
}