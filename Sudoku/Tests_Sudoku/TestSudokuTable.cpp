
#include "stdafx.h"

#include <gtest\gtest.h>
#include <gmock\gmock.h>

#include "..\Sudoku\SudokuTable.h"


TEST(SudokuTable, SudokuTableHas81Elements)
{
    SudokuTable sudoku;
    EXPECT_EQ(NUMBERS_IN_SUDOKU, sudoku.allpCells.size());
}


TEST(SudokuTable, LocationOfFirstIndex)
{
    SudokuTable sudoku;
    EXPECT_EQ(0, sudoku.allpCells[0]->location.index);
    EXPECT_EQ(0, sudoku.allpCells[0]->location.row);
    EXPECT_EQ(0, sudoku.allpCells[0]->location.col);
    EXPECT_EQ(0, sudoku.allpCells[0]->location.square);
}


TEST(SudokuTable, LocationOfLastIndex)
{
    SudokuTable sudoku;
    EXPECT_EQ(80, sudoku.allpCells[NUMBERS_IN_SUDOKU - 1]->location.index);
    EXPECT_EQ(8, sudoku.allpCells[NUMBERS_IN_SUDOKU - 1]->location.row);
    EXPECT_EQ(8, sudoku.allpCells[NUMBERS_IN_SUDOKU - 1]->location.col);
    EXPECT_EQ(8, sudoku.allpCells[NUMBERS_IN_SUDOKU - 1]->location.square);
}


TEST(SudokuTable, LocationOfSomethingInTheMiddle)
{
    int somewhere = 42;
    SudokuTable sudoku;
    EXPECT_EQ(somewhere, sudoku.allpCells[somewhere]->location.index);
    EXPECT_EQ(4, sudoku.allpCells[somewhere]->location.row);
    EXPECT_EQ(6, sudoku.allpCells[somewhere]->location.col);
    EXPECT_EQ(5, sudoku.allpCells[somewhere]->location.square);
}


TEST(SudokuTable, PointersToAllCellsInRow)
{
    SudokuTable sudoku;
    for (int row = 0; row < SUDOKU_MAGIC_NUMBER; ++row)
    {
        EXPECT_EQ(SUDOKU_MAGIC_NUMBER, sudoku.getRow(row).size());
        for (auto r : sudoku.getRow(row))
            EXPECT_EQ(row, r->location.row);
    }
}

/*
TEST(SudokuTable, PointersToAllCellsInRowByPointers)
{
    SudokuTable sudoku;
    for (int row = 0; row < SUDOKU_MAGIC_NUMBER; ++row)
    {   
        std::vector<int> expected;
        for (int i = 0; i < SUDOKU_MAGIC_NUMBER; ++i)
            expected.push_back(row);
        
        for (auto r : sudoku.getRow(row))
            for (int i = 0; i < )
            EXPECT_EQ(row, sudoku.getRow(sudoku[]))
    }

}
*/


TEST(SudokuTable, PointersToAllCellsInColumns)
{
    SudokuTable sudoku;
    for (int col = 0; col < SUDOKU_MAGIC_NUMBER; ++col)
    {
        EXPECT_EQ(SUDOKU_MAGIC_NUMBER, sudoku.getColumn(col).size());
        for (auto c : sudoku.getColumn(col))
            EXPECT_EQ(col, c->location.col);
    }
}


TEST(SudokuTable, PointersToAllCellsInSquare)
{
    SudokuTable sudoku;
    
    for (int square = 0; square < SUDOKU_MAGIC_NUMBER; ++square)
    {
        EXPECT_EQ(SUDOKU_MAGIC_NUMBER, sudoku.getSquare(square).size());
        for (auto s : sudoku.getSquare(square))
            EXPECT_EQ(square, s->location.square);
    }
}
