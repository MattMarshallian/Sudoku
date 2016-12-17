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


std::vector<Cell*> SudokuTable::getRow(int index)
{  
    auto iter_first = allpCells.begin() + index * SUDOKU_MAGIC_NUMBER;
    auto iter_last = iter_first + SUDOKU_MAGIC_NUMBER;
    std::vector<Cell*> row(iter_first, iter_last);
    return row;
}

std::vector<Cell*> SudokuTable::getRow(Cell* pCell)
{
    return getRow(pCell->location.row);
}


std::vector<Cell*> SudokuTable::getColumn(int index)
{
    std::vector<Cell*> col;
    auto iter = allpCells.begin() + index;
    for (auto i = 0; i < SUDOKU_MAGIC_NUMBER; ++i)
        col.push_back(*iter);
    return col;
}

std::vector<Cell*> SudokuTable::getColumn(Cell* pCell)
{
    return getColumn(pCell->location.col);
}


std::vector<Cell*> SudokuTable::getSquare(int index)
{
    std::vector<Cell*> square;
    int offset = 0;

    switch (index)
    {
        case 0: offset = 0; break;
        case 1: offset = 3; break;
        case 2: offset = 6; break;
        case 3: offset = 27; break;
        case 4: offset = 30; break;
        case 5: offset = 33; break;
        case 6: offset = 54; break;
        case 7: offset = 57; break;
        case 8: offset = 60; break;
    }

    for (int r = 0; r < 3; ++r)
    {
        auto iter = allpCells.begin() + offset + r * SUDOKU_MAGIC_NUMBER;
        for (int c = 0; c < 3; ++c)
            square.push_back(*(iter + c));
    }

    return square;
}

std::vector<Cell*> SudokuTable::getSquare(Cell* pCell)
{
    return getSquare(pCell->location.square);
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