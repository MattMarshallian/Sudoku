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

    std::vector<Cell*> getRow(int index);      // zwraca wektor pointer�w do kom�rek we wskazanym rz�dzie
    std::vector<Cell*> getRow(Cell* pCell);    // przeci��ona metoda

    std::vector<Cell*> getColumn(int index);   // zwraca wektor pointer�w do kom�rek we wskazanej kolumnie
    std::vector<Cell*> getColumn(Cell* pCell); // przeci��ona metoda

    std::vector<Cell*> getSquare(int index);   // zwraca wektor pointer�w do kom�rek we wskazanym kwadracie
    std::vector<Cell*> getSquare(Cell* pCell); // przeci��ona metoda

private:
    int setFixRow(Cell* pCell);
    int setFixColumn(Cell* pCell);
    int setFixSquare(Cell* pCell);
};

