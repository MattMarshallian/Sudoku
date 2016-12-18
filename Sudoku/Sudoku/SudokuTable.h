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

    std::vector<Cell*> getRow(int index);      // zwraca wektor pointerów do komórek we wskazanym rzêdzie
    std::vector<Cell*> getRow(Cell* pCell);    // przeci¹¿ona metoda

    std::vector<Cell*> getColumn(int index);   // zwraca wektor pointerów do komórek we wskazanej kolumnie
    std::vector<Cell*> getColumn(Cell* pCell); // przeci¹¿ona metoda

    std::vector<Cell*> getSquare(int index);   // zwraca wektor pointerów do komórek we wskazanym kwadracie
    std::vector<Cell*> getSquare(Cell* pCell); // przeci¹¿ona metoda

    bool isValid();

private:
    int setFixRow(Cell* pCell);
    int setFixColumn(Cell* pCell);
    int setFixSquare(Cell* pCell);
};

